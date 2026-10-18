class Solution {
public:
    int cnt;
    vector<bool> vis;
    void dfs(vector<vector<int>>& grid, int s){
        for(auto it : grid[s]){
            if(!vis[it]){
                vis[it] = true;
                cnt--;
                dfs(grid, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        cnt = rooms.size();
        vis.assign(cnt, false);
        for(int i = 0; i < cnt; i++){
            if(!rooms[i].empty()){
                vis[i] = true;
                dfs(rooms, i);
                break;
            }
        }
        return cnt <= 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna