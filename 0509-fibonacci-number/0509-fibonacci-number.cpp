class Solution {
public:
    int recursion(int n, vector<int>& dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        int left = recursion(n - 1, dp);
        int right = recursion(n - 2, dp);
        return dp[n] =  left + right;
        // reduces O(2^n) complexity to O(n) itself
    }
    int fib(int n) {
        // simple and works but time complexity is 2^n
        if(n <= 1) return n;
        vector<int> dp(n + 1, -1); // -> create a 1d dimension array and initialize it with a value which is unreachable
        return recursion(n, dp);

        // int left = fib(n - 1);
        // int right = fib(n - 2);
        // return left + right;

        // to reduce time complexity we will use DP

        // DP -> RECURSIVE SOLUTION + OVERLAPPING SUBPROBLEM
        // CONVERT RECURSION -> DP, JUST ADD STORING VALUES INSIDE RECURSION


        
    }
};