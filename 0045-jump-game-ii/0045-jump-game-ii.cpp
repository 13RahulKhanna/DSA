class Solution {
public:
    int n;
    vector<int> dp;
    int fn(vector<int>& nums, int i){
        if(i >= n - 1) return 0;
        if(dp[i] != -1) return dp[i];

        int k = nums[i], ans = INT_MAX / 4;
        
        for(int j = i + 1; j <= min(i + k, n); j++){
            ans = min(ans, 1 + fn(nums, j));
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);

        return fn(nums, 0);
    }
};