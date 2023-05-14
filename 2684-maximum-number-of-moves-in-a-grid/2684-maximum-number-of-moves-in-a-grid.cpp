class Solution
{
private:
    int rec(int i, int j,  vector<vector<int>> &g, vector<vector<long long>> &dp)
    {
        int r = g.size();
        int c = g[0].size();

        if (dp[i][j] != -1)
            return dp[i][j];

        long long a = 0, b = 0, cc = 0;
        if (i > 0 && j < c - 1 && g[i][j] < g[i - 1][j + 1])
            a = rec(i - 1, j + 1, g, dp) + 1;
        
        if (j < c - 1 && g[i][j] < g[i][j + 1])
            b = rec(i, j + 1, g, dp) + 1;

        if (i < r - 1 && j < c - 1 && g[i][j] < g[i + 1][j + 1])
            cc = rec(i + 1, j + 1, g, dp) + 1;
        
        return dp[i][j] = max({a, b, cc});
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {   
        int n = grid.size();
        vector<vector<long long>> dp(n+1,vector<long long>(grid[0].size()+1,-1));
        int ans = 0;
        for(int i=0;i< n;++i) // Calling recursive function for every cell in first column.
        {
            int x = rec(i, 0, grid, dp);
            ans = max(ans, x);
        }
        return ans;
    }
};