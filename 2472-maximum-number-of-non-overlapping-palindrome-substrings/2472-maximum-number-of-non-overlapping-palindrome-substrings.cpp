class Solution {
public:
    
    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            
            if(i + k - 1 < n && isPal(s, i, i + k - 1)){
                ans++;
                i = i + k - 1;
            }
            else if(i + k < n && isPal(s, i, i + k)){
                ans++;
                i = i + k;
            }
        }

        return ans;
    }
};