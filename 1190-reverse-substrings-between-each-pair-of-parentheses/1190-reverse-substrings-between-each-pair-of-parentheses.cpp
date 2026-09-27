
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<pair<int,int>> brackets;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                brackets.push_back({st.top(), i});
                st.pop();
            }
        }

        for (auto [i, j] : brackets) {
            reverse(s.begin() + i + 1, s.begin() + j);
        }

        string ans;
        for (char c : s) {
            if (c != '(' && c != ')')
                ans += c;
        }

        return ans;
    }
};