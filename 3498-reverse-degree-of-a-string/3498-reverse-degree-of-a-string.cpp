class Solution {
public:
    int reverseDegree(string s) {
        int prod = 1, ans = 0;

        for(auto ch : s){
            ans += prod * (abs(ch - 'z' - 1));
            prod++;
        }
        return ans;
    }
};