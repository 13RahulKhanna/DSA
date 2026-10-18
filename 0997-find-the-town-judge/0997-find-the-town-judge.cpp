class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n+1,0);
        vector<vector<int>> adj(n+1);
        // for(int i = 0;i<n;i++) v[i] = i+1;
        for(auto it : trust){
            v[it[0]] = -1;
            adj[it[1]].push_back(it[0]);
        }
        // for(auto it : v) cout << it << endl;


        // 1 -> 2 3
        // 3 -> 1 2
        for(int i = 1;i<=n;i++){
            if(v[i] == -1) continue;
            if(adj[i].size() == n-1) return i;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna