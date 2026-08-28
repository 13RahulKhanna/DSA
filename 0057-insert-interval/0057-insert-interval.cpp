class Solution {
public:
    // insert into interval where intervals[i] second >= newInterval first then iterate and keep merging
    // 1 3, 2 4 -> 1 4 
    // 1 5 0 3
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(auto it : intervals) cout << it[0] << " " << it[1] << endl;
        int ptr = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= ans[ptr][1]){
                ans[ptr][1] = max(intervals[i][1],ans[ptr][1]);
            }
            else{
                ans.push_back(intervals[i]);
                ptr++;
            }
        }


        return ans;
    }
};