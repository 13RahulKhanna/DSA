class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int ans = 0;
        while(!q.empty() && fresh > 0){
            int sz = q.size();
            while(sz--){
                auto [i, j] = q.front(); 
                q.pop();

                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = {0, -1, 0, 1};

                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni, nj});
                    }
                }

            }
            ans++;
        }
        return fresh == 0 ? ans : -1;
    }
};