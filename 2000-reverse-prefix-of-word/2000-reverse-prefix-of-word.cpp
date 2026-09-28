class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        stack<char> st;
        bool fl = true;

        for(int i = 0; i < word.size(); i++){
            st.push(word[i]);
            if(word[i] == ch){
                fl = false;
                break;
            }
        }

        if(fl) return word;

        int cnt = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
            cnt++;
        }
        ans += word.substr(cnt);
        return ans;
    }
};