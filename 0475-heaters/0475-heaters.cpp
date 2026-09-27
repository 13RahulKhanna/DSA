
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0;

        for (int h : houses) {
            auto it = lower_bound(
                heaters.begin(), heaters.end(), h
            );

            int dist = INT_MAX;

            if (it != heaters.end()) {
                dist = min(dist, abs(*it - h));
            }

            if (it != heaters.begin()) {
                dist = min(dist, abs(*prev(it) - h));
            }

            ans = max(ans, dist);
        }

        return ans;
    }
};