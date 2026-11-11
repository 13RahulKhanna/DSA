class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        int mn = cost1;
        if(need1 < need2) mn = cost2;
        

        return min(min(need1 * cost1 + need2 * cost2, costBoth * max(need1, need2)), costBoth * min(need1, need2) + abs(need1 - need2) * mn);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna