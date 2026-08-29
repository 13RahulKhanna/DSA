class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m / 2; i++){
            swap(matrix[i], matrix[m - 1 - i]);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > j) swap(matrix[i][j], matrix[j][i]);
            }
        }

        return;
    }
};