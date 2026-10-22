class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int total = 0, n = nums.size();

        for(int i = 0; i < n; i++){
            if(i % 2 == 0) total += nums[i];
            else total -= nums[i];
        }
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna