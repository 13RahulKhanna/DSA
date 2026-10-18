class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> v(n+1,false);
        vector<vector<int>> adj(n+1);
        for(auto it : trust){
            v[it[0]] = true;
            adj[it[1]].push_back(it[0]);
        }


        // 1 -> 2 3
        // 3 -> 1 2
        for(int i = 1;i<=n;i++){
            if(v[i]) continue;
            if(adj[i].size() == n-1) return i;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna