class Solution {
public:
    // initialise
    vector<vector<int>> dp;
    int fn(vector<vector<int>>& grid, int m, int n){                               // FUNCTION PARAMETER
        if(m == 0 && n == 0) return grid[m][n];                  // BASE CASE
        if(m == -1 || n == -1) return INT_MAX / 2;                // BASE CASE
        if(dp[m][n] != INT_MAX / 2) return dp[m][n];             // dp base case

        return dp[m][n] = min(grid[m][n] + fn(grid, m - 1, n), grid[m][n] + fn(grid, m, n - 1));             // RECURSIVE CALLS
    }
    int minPathSum(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        
        dp.assign(m + 1, vector<int>(n + 1, INT_MAX / 2));
        return fn(grid, m - 1, n - 1);                        // CALL RECURSION 
    }
};