class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt = 0, ans = 0;

        for(auto it : s){
            if(it  == '('){
                st.push(it);
                cnt++;
            }
            if(it == ')'){
                st.pop();
                cnt--;
            }
            ans = max(ans, cnt);
        }

        return ans;

    }
};