
class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool dfs(vector<vector<char>>& grid, int i, int j, int bal) {
        if (i >= m || j >= n) return false;

        if (grid[i][j] == '(') bal++;
        else bal--;

        if (bal < 0) return false;

        int remaining = (m - 1 - i) + (n - 1 - j);
        if (bal > remaining) return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool down = dfs(grid, i + 1, j, bal);
        bool right = dfs(grid, i, j + 1, bal);

        return dp[i][j][bal] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')')
            return false;

        memset(dp, -1, sizeof(dp));

        return dfs(grid, 0, 0, 0);
    }
};