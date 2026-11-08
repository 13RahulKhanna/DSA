class Solution {
public:
    int m,n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    int dfs(vector<vector<int>>& grid, int i,int j){
        int connection = 0;
        for(int d = 0;d<4;d++){
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1){
                grid[ni][nj] = 0;
                connection += 1 + dfs(grid,ni,nj);
            }
        }
        return connection;
    }    
    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<int> rowConnection(m,0);
        vector<int> colConnection(n,0);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    rowConnection[i]++;
                    colConnection[j]++;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && (rowConnection[i] > 1 || colConnection[j] > 1)){
                    ans++;
                }
            }
        }
        return ans;
        
    }

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna