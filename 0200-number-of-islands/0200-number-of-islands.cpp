class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int m, n;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n ) return;
        grid[i][j] = '0';

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1'){
                dfs(grid, ni, nj);
            }
        }
    }
    int dfs(vector<vector<char>>& grid){
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    int numIslands(vector<vector<char>>& grid) {
        // 2 ways -> DFS and BFS
        return dfs(grid);


    }
};