class Solution {
public:
    bool isPalindrome(string s) {
        string plain = "";
        for(auto it : s){
            if(it >= 'A' && it <= 'Z') plain += char('a' + (it - 'A'));
            if(it >= 'a' && it <= 'z') plain += it;
            if(it >= '0' && it <= '9') plain += it;
        }

        int i = 0, j = plain.size() - 1;

        while(i <= j){
            if(plain[i] != plain[j]) return false;
            i++; j--;
        }
        return true;
    }
};