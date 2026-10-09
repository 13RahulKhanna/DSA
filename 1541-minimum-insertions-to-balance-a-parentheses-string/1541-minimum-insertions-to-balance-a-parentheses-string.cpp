class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                // Step 1: make a "))"
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++;

                // Step 2: find its '('
                if (open > 0) open--;
                else ans++;
            }
        }

        return ans + open * 2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna