class Solution {
public:
    int minRotations(string s) {
        int ans = 0, ptr = 0;

        for(auto ch : s){
            int num = ch - '0';

            ans += min(abs(num - ptr), 10 - abs(ptr - num));
            ptr = num;
            // cout << ans << endl;
        }

        return ans;
    }
};