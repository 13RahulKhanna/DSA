class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> ans;

        while(top <= bottom && left <= right){
            // cout << top << " " << bottom << " " << left << " " << right <<" x" << endl;
            for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
            top++;
            // cout << "y" << endl;
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;
            if(top > bottom || left > right) break;
            // cout << right << " " <<  left << " z" << endl;

            for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
            bottom--;
            // cout << "a" << endl;
            
            for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
            // cout << "b" << endl;
           
        }
        return ans;

    }
};