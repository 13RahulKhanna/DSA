class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();
                
                vector<int> dx = {-1,0,1,0};
                vector<int> dy = {0,-1,0,1};
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0){
                        q.push({ni,nj});
                        grid[ni][nj] = 1;
                    }
                }
            }
            if(q.empty()) break;
            ans++;
        }
        if(ans == 0) return -1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna