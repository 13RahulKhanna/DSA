class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> preEven(n + 1, 0), preOdd(n + 1, 0);

        // Build prefix sums
        for (int i = 0; i < n; i++) {
            preEven[i + 1] = preEven[i];
            preOdd[i + 1] = preOdd[i];
            if (i % 2 == 0) preEven[i + 1] += nums[i];
            else preOdd[i + 1] += nums[i];
        }

        int totalEven = preEven[n];
        int totalOdd = preOdd[n];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int evenBefore = preEven[i];
            int oddBefore = preOdd[i];

            int evenAfter = totalEven - preEven[i + 1];
            int oddAfter = totalOdd - preOdd[i + 1];

            // parity flips after removal
            int newEven = evenBefore + oddAfter;
            int newOdd = oddBefore + evenAfter;

            if (newEven == newOdd) ans++;
        }

        return ans;
    }
};
