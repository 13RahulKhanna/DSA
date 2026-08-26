class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, right = 0;
        string ans = "";

        for(right; right < s.size(); right++){
            if(s[right] == '1') k--;


            while(k < 0 || s[left] == '0'){
                if(s[left] == '1') k++;
                left++;
            }

            if(k == 0){
                int len = right - left + 1;

                if(len < ans.size() || ans.empty()){
                    ans = s.substr(left, right - left + 1);

                }      
                if(len == ans.size()){
                    ans = min(ans, s.substr(left,right - left + 1));
                }        
            }           
        }
        return ans;
    }
};