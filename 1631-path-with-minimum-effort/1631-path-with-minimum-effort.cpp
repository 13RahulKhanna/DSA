
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int val = pq.top().first;
            pq.pop();

            if(val > dist[x][y]) continue;

            if(x == m - 1 && y == n - 1)
                return val;

            for(int k = 0; k < 4; k++) {
                int ni = x + dx[k];
                int nj = y + dy[k];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int effort = max(val, abs(heights[ni][nj] - heights[x][y]));

                    if(effort < dist[ni][nj]) {
                        dist[ni][nj] = effort;
                        pq.push({effort, {ni, nj}});
                    }
                }
            }
        }

        return 0;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna