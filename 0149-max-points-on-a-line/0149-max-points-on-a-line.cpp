class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<double, int> mp;

            for (int j = i + 1; j < n; j++) {

                if (points[i][0] == points[j][0]) {
                    mp[1e9]++;
                }
                else {
                    double slope =
                        1.0 * (points[j][1] - points[i][1]) /
                        (points[j][0] - points[i][0]);

                    mp[slope]++;
                }
            }

            int mx = 0;

            for (auto [slope, cnt] : mp) {
                mx = max(mx, cnt);
            }

            ans = max(ans, mx + 1);
        }

        return ans;
    }
};