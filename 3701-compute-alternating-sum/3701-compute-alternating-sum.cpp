class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int total = 0, n = nums.size();
        if(n == 1) return nums[0];

        for(int i = 0; i < n; i+=2){
            if(i == n - 1) continue;
            total += (nums[i] - nums[i + 1]);
        }
        if(n % 2 == 1) total += nums[n - 1]; 
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna