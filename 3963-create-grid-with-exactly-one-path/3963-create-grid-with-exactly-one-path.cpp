class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(vector<string>& grid, int i, int j){
        if(i == 0 && j == 0){
            grid[i][j] = '.';
            return;
        }
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size()){
                grid[ni][nj] = '.';
                dfs(grid, ni, nj);
                return;
            }
        }
        
    }
    vector<string> createGrid(int m, int n) {
        string str(n, '#');
        vector<string> grid(m, str);
        grid[m - 1][n - 1] = '.';
        dfs(grid, m - 1, n - 1);
        return grid;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna