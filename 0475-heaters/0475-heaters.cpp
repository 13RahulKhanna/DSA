class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        for(int i = 0; i < houses.size(); i++){
            int h = houses[i], local = INT_MAX;
            
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            if(it != heaters.end()) local = min(local, *it - h);

            if(it != heaters.begin()) local = min(local, h - *prev(it));

            ans = max(ans, local);
        }

        return ans;
        



    }
};