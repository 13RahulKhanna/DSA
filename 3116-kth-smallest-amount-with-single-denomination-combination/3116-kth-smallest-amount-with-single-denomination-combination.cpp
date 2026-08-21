class Solution {
public:
    using ll = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        // Remove redundant coins.
        // If x is divisible by an earlier coin,
        // all multiples of x are already covered.
        vector<int> v;

        for (int x : coins) {
            bool ok = true;

            for (int y : v) {
                if (x % y == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                v.push_back(x);
        }

        int n = v.size();

        // lcm[mask] = LCM of all coins represented by mask
        int m = 1 << n;
        vector<ll> lcm(m, 1);

        ll lo = k;
        ll hi = 1LL * v[0] * k;

        for (int mask = 1; mask < m; mask++) {
            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);

            ll g = gcd(lcm[prev], (ll)v[bit]);
            ll cur = lcm[prev] / g;

            // Avoid overflow / uselessly large LCM
            if (cur > hi / v[bit])
                lcm[mask] = hi + 1;
            else
                lcm[mask] = cur * v[bit];
        }

        // Count numbers <= x divisible by at least one coin
        auto count = [&](ll x) {
            ll cnt = 0;

            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x)
                    continue;

                if (__builtin_popcount(mask) & 1)
                    cnt += x / lcm[mask];
                else
                    cnt -= x / lcm[mask];
            }

            return cnt;
        };

        // Binary search kth smallest
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};