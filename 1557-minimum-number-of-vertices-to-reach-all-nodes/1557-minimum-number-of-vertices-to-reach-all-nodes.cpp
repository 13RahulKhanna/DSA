class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n);
        vector<int> ans;
       
        for (auto& it: edges)
            seen[it[1]] = true;

        for (int i = 0; i < n; ++i)
            if (!seen[i])
                ans.push_back(i);
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna