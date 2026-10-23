class Solution {
public:
    int scoreOfString(string s) {
        int total_sum = 0;
        int n = s.size();

        for(int i = 1; i < n; i++){
            int neighbour = s[i] - s[i - 1];

            total_sum += abs(neighbour);
        }

        return total_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna