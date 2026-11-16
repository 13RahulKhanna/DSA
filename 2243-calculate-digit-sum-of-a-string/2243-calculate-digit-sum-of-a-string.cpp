class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string tmp;  // The string after each round
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int val = 0;
                for (int j = i; j < min(i + k, n); ++j) {
                    val += s[j] - '0';
                }
                tmp.append(to_string(val));
            }
            s = tmp;
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna