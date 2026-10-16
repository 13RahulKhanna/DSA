
class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> sum, sumSq, lazy;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        sumSq[node] = (sumSq[node] + 2 * val * sum[node] % mod
                     + val * val % mod * len % mod) % mod;

        sum[node] = (sum[node] + val * len) % mod;
        lazy[node] += val;
    }

    void push(int node, int l, int r) {
        if(lazy[node] == 0 || l == r) return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void pull(int node) {
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % mod;
        sumSq[node] = (sumSq[node * 2] + sumSq[node * 2 + 1]) % mod;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i);

            ans = (ans + sumSq[1]) % mod;

            last[nums[i]] = i;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna