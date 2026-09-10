class Solution {
public:

    bool fn(string& s, map<string,int>& mp, vector<int>& dp, int i) {

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        string cur = "";

        for(int j = i; j < s.size(); j++) {

            cur.push_back(s[j]);

            if(mp[cur]) {

                if(fn(s, mp, dp, j + 1))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        map<string,int> mp;

        for(auto it : wordDict)
            mp[it]++;

        vector<int> dp(s.size(), -1);

        return fn(s, mp, dp, 0);
    }
};