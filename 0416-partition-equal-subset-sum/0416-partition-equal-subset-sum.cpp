class Solution {
public:
    bool fn(vector<int>& nums, int n, int sum, vector<vector<int>>& dp){              // SUM = TOTAL SUM / 2
        if(n < 0){                                          // OUT OF BOUND -> FALSE
            if(sum == 0) return true;                       // REACHES THE END AND SUM == 0 WHICH MEANS  
            return false;                                   // unable
        }
        if(sum < 0) return false;                      // out of bound return false  
        if(dp[n][sum] != -1) return dp[n][sum];                      

        return dp[n][sum] = fn(nums, n - 1, sum - nums[n], dp) || fn(nums, n - 1, sum, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto x : nums) sum += x;
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));                    // initialise dp
        return fn(nums,n - 1,sum / 2, dp);
    }
};