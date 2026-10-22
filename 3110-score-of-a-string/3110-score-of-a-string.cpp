class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        for(int i = 1;i<s.size();i++){
            total += abs(s[i] - s[i-1]);
        }
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna