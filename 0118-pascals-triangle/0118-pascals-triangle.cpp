class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});

        for(int i = 1;i<numRows;i++){
            vector<int> dp1(i+1);
            dp1[0] = dp1.back() = 1;

            for(int j = 1;j<i;j++){
                dp1[j] = dp[i-1][j] + dp[i-1][j-1];
            }

            dp.push_back(dp1);
        }

        return dp;

    }
};