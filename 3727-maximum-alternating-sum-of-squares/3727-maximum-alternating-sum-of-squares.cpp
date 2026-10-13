class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            long long small = nums[i];
            long long large = nums[n - 1 - i];

            ans += large * large - small * small;
        }

        if (n % 2) {
            long long mid = nums[n / 2];
            ans += mid * mid;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna