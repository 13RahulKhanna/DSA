class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ptr = 0, n = intervals.size(), ans = 0;

        for(int i = 1; i < n; i++){
            // cout << intervals[i][0] << " " << intervals[i][1] << " " << ans << endl;
            if(intervals[ptr][1] > intervals[i][0]){
                ans++;
                
                if(intervals[i][1] < intervals[ptr][1])
                    ptr = i;
            }
            else{
                ptr = i;
            }
        }
        return ans;
    }
};