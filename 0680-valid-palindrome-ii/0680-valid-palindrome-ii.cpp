class Solution {
public:
    bool fn(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]){
                return fn(s, i + 1, j) | fn(s, i, j - 1);
            }
            else{
                i++; j--;
            }
        }
        return true;
    }
};