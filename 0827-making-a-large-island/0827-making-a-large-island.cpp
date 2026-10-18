class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    
    int dfs(vector<vector<int>>& grid, int i, int j, int num){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        int cnt = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1){
                grid[ni][nj] = num;               
                cnt += dfs(grid, ni, nj, num);
            }
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int num = 2;
        vector<int> v = {0, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = num;
                    int cnt = dfs(grid, i, j, num);
                    v.push_back(cnt);
                    num++;
                }
            }
        }
        int ans = 0;
        for(auto it : v) ans = max(ans, it);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 0){
                    int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
                    for(int k = 0; k < 4; k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != 0){
                            if(p1 == -1){
                                p1 = grid[ni][nj];
                            }
                            else if(p2 == -1 && grid[ni][nj] != p1){
                                p2 = grid[ni][nj];
                            }
                            else if(p3 == -1 && grid[ni][nj] != p1 && grid[ni][nj] != p2){
                                p3 = grid[ni][nj];
                            }
                            else{
                                if(grid[ni][nj] != p1 && grid[ni][nj] != p2 && grid[ni][nj] != p3)
                                    p4 = grid[ni][nj];
                            }
                        }
                        
                    }
                    if(p1 == -1) continue;
                    else if(p2 == -1){
                        ans = max(ans,v[p1] + 1);
                    }
                    else if(p3 == -1){
                        ans = max(ans,v[p1] + v[p2] + 1);
                    }
                    else if(p4 == -1){
                        ans = max(ans, v[p1] + v[p2] + v[p3] + 1);
                    }
                    else{
                        ans = max(ans,v[p1] + v[p2] + v[p3] + v[p4] + 1);
                    }
                }
            }
        }
        // for(auto it : grid){
        //     for(auto itt : it) cout << itt << " ";
        //     cout << endl;
        // }
        // for(auto it : v) cout << it << " ";
        if(ans == 0) return 1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna