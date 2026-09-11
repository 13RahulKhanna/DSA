class Solution {
public:
    // initialise
    vector<vector<int>> dp;
    int fn(int m, int n){                               // FUNCTION PARAMETER
        if(m == 0 && n == 0) return 1;                  // BASE CASE
        if(m == -1 || n == -1) return 0;                // BASE CASE
        if(dp[m][n] != -1) return dp[m][n];             // dp base case

        return dp[m][n] = fn(m - 1, n) + fn(m, n - 1);             // RECURSIVE CALLS
    }
    int uniquePaths(int m, int n) {
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return fn(m - 1, n - 1);                        // CALL RECURSION 
    }
};