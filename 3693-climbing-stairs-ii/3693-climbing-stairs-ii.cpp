class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 0) return 0;
        if (n == 1) return costs[0] + 1;
        if (n == 2) return min(costs[0] + 1 + costs[1] + 1, costs[1] + 4);

        int dp0 = costs[0] + 1;
        int dp1 = min(costs[0] + 1 + costs[1] + 1, costs[1] + 4);
        int dp2 = min({costs[0] + 1 + costs[1] + 1 + costs[2] + 1,
                       costs[0] + 1 + costs[2] + 4, 
                       costs[1] + 4 + costs[2] + 1,
                       costs[2] + 9});

        // if (n == 3) return dp2;

        for (int i = 3; i < n; i++) {
            int curr = min({dp2 + costs[i] + 1,
                            dp1 + costs[i] + 4,
                            dp0 + costs[i] + 9});
            dp0 = dp1;
            dp1 = dp2;
            dp2 = curr;
        }

        return dp2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna