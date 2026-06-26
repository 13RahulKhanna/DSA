class Solution {
public:
    int MOD = 1e9 + 7;

    int rearrangeSticks(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                dp[i][j] =
                    (
                        dp[i - 1][j - 1]
                        +
                        (i - 1LL) * dp[i - 1][j]
                    ) % MOD;
            }
        }
        return dp[n][k];
    }
};