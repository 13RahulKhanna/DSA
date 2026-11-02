class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;
        if(nums.size() % 2 == 1){
            ans = ans + nums[nums.size() - 1];
            
        }

        for(int i = 0; i < nums.size() - 1; i+=2){
            ans += nums[i] - nums[i + 1];
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna