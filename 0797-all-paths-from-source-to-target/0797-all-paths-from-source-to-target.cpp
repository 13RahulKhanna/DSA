class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<vector<int>>& graph, int s, int d){
        if(s == d){
            ans.push_back(path);
            return;
        }
        for(auto it : graph[s]){
            path.push_back(it);
            dfs(graph, it, d);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna