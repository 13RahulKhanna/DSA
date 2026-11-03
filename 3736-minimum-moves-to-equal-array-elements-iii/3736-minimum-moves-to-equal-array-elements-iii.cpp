class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0;
        for(auto it : nums){
            mx = max(mx, it);
        }
        int ans = 0;
        for(auto it : nums){
            ans += mx - it;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna