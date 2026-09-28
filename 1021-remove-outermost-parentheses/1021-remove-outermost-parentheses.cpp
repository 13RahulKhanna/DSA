class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0, right = 0;
        queue<char> st;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                left++;
            }
            else{
                right++;
            }
            st.push(s[i]);
            if(left == right){
                if(left > 1){
                    st.pop();
                    while(!st.empty()){
                        ans += st.front();
                        st.pop();
                    }
                    ans.pop_back();
                }
                else if (left == 1){
                    st.pop(); st.pop();
                }
            }
            
        }

        return ans;

    }
};