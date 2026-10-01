class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x : s){
            if(x == '(' || x == '{' || x == '[') st.push(x);
            else if(st.empty()) return false;
            else if(st.top() == '(' && x == ')') st.pop();
            else if(st.top() == x - 2) st.pop();
            else return false;
        }
        return st.empty();
    }
};