class Solution {
public:
    string ans = "";

    void fn(string& s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        int len = j - i - 1;

        if(len > ans.size())
            ans = s.substr(i + 1, len);
    }

    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            fn(s, i, i); fn(s, i, i + 1); 
        }

        return ans;
    }
};