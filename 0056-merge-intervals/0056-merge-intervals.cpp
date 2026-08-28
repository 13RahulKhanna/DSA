class Solution {
public:
    // overlap = 1 3, 2 5 -> first end >= second start = overlap if so combine first start and second end

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(), ptr = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);


        for(int i = 1; i < n; i++){
            int st = intervals[i][0], end = intervals[i][1];
            if(st <= ans[ptr][1]){
                ans[ptr][1] = max(ans[ptr][1], end);
            }
            else{
                ans.push_back(intervals[i]);
                ptr++;
            }
        }

        return ans;
    }
};