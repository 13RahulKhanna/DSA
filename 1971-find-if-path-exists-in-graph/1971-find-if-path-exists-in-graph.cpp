class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int s, int d){
        int ans = false;
        if(s == d) return true;
        for(auto it : adj[s]){
            if(!vis[it]){
                vis[it] = true;
                ans = ans | dfs(adj, vis, it, d);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return dfs(adj, vis, source, destination);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna