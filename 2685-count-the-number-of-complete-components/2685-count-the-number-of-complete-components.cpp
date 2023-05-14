const int N=1e6;
int DsuParent[N];
int DsuSize[N];

void make(int v)
{
    DsuParent[v] = v;
    DsuSize[v] = 1;
}

int parentFind(int v)
{
    if (DsuParent[v] == v)
        return v;
    return DsuParent[v] = parentFind(DsuParent[v]);
}

void Union(int a, int b)
{
    a = parentFind(a);
    b = parentFind(b);

    if (a != b)
    {
        if (DsuSize[a] < DsuSize[b])
            swap(a, b);
        DsuParent[b] = a;
        DsuSize[a] += DsuSize[b];
    }
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int si = edges.size();
        for(int i=0;i<n;++i){
			make(i);
		}
        
		map<int,int>m;
		for(int i=0;i<si;++i){
			m[edges[i][0]]++;
			m[edges[i][1]]++;
            Union(edges[i][0],edges[i][1]);
		}

        set<int>s;
		map<int,vector<int>>p;
		for(int i=0;i<n;++i){
			int x = parentFind(i);
			p[x].push_back(i);
            s.insert(x);
		}

		int ans=s.size();

        for (auto it:p){
			int x=DsuSize[it.first];
			for(auto i:it.second){
				DsuSize[i]=x;
			}
		}

		for(auto it:p){
			for(auto i:it.second){
				if(DsuSize[i]-1 != m[i]){
					ans--;
					break;
				}
			}
		}
		return ans;
    }
};