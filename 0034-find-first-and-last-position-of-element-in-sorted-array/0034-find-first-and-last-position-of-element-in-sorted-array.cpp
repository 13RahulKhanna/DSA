class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);

        int low_idx = low - nums.begin();
        int high_idx = high - nums.begin();
        high_idx--;

        if(low == nums.end() || *low != target) return {-1,-1};
        return {low_idx, high_idx};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna