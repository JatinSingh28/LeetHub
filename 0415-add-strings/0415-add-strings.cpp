#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, a, n) for (int i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it : a)
#define printv(v)                     \
    itr(it, v) { cout << it << ' '; } \
    cout << '\n';
#define print(n) cout << n << '\n';
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
const int mod = 1e9 + 7;

// DFS **************************************************************

const int N = 1e6 + 1;
vi g[N];
// int vis[N];
vi level(N, 0);
vi call(N, -1);
bool f = 0;
void dfs(int node, vvi &v, vi &vis)
{
    vis[node] = 1;
    for (auto it : v[node])
    {
        if (!vis[it])
        {
            dfs(it, v, vis);
        }
    }
}
// DFS *************************************************************

// BFS *************************************************************

void bfs(int p, vi &v, vi &dist, int d)
{
    queue<int> q;
    q.push(p);
    dist[p] = 0;
    if (d == 0)
        return;
    // ans[p.first*m+p.second] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        v[x] = 1;
        for (auto it : g[x])
        {
            if (!v[it])
            {
                // deb(dist[x]);
                dist[it] = dist[x] + 1;
                // deb2(it,dist[it]);
                if (dist[it] > d)
                    return;
                v[it] = 1;
                q.push(it);
            }
        }
    }
}

// BFS *************************************************************

// DSU by size and path compression *********************************

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
// DSU ***************************************************************

ll power(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return r;
}

//==========================================================

class Solution {

private:
string ans;
void rec(int i,int c,string &s,string &t){
    if(i==-1)   {
        if(c)
            ans.pb('1');
        return;
    }
        
    int a = s[i]-'0';
    int b = t[i]-'0';
    int sum = a+b+c;
    if(sum<10){
        ans.pb(to_string(sum)[0]);
        rec(i-1,0,s,t);
    }
    else{
        ans.pb(to_string(sum)[1]);
        rec(i-1,1,s,t);
    }
        

}
public:
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        if(n>m){
            swap(num1,num2);
            swap(n,m);
        }
            
        int diff = m-n;
        string s;
        fo(i,diff){
            s.pb('0');
        }
        
        s.insert(s.end(),all(num1));
        deb2(s,num2);
        rec(m-1,0,s,num2);
        reverse(all(ans));
        return ans;

    }
};