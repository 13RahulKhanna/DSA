class Solution {
public:
    int fn(vector<int>& nums, int n, vector<int>& dp){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int rob = nums[n] + fn(nums, n - 2, dp);
        int skip = fn(nums, n - 1, dp);

        return dp[n] = max(rob, skip);
        // 2^n, n^2
    }
    int rob(vector<int>& nums) {
        // rob 1 skip 2 orr skip 1 rob 2 orr skip 1 skip 2.. rob n but why skip 1 when rob 3 is fine with rob 1
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n + 2, -1);       
        return fn(nums,n-1, dp);

        // dp[0] = nums[0];
        // dp[1] = max(dp[0],nums[1]);
        // for(int i = 2;i<n;i++){
        //     dp[i] = max(dp[i-1],nums[i] + dp[i-2]);
        // }
        // return dp[n-1];
    }
};