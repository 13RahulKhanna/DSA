class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(30, 0);

        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num & (1 << i)) {
                    cnt[i]++;
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            for (int j = 29; j >= 0; j--) {
                if (cnt[j] > 0) {
                    cur |= (1LL << j);
                    cnt[j]--;
                }
            }
            res = (res + cur * cur) % MOD;
        }

        return (int)res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna