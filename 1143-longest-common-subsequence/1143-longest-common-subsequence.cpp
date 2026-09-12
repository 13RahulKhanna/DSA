class Solution {
public:
    int n, m;
    int fn(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int skip1 = 0, pick = 0, skip2 = 0;
        if(text1[i] == text2[j]) return dp[i][j] = pick = 1 + fn(text1, text2, i + 1, j + 1, dp);
        skip1 = fn(text1,text2, i + 1, j, dp);
        skip2 = fn(text1,text2, i, j + 1, dp);
        return dp[i][j] = max(pick, max(skip1, skip2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(); m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(text1, text2, 0, 0, dp);
    }
};