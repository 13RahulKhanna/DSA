class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        long long cnt = 0;
        int mod = 1e9 + 7;
        map<int,int> mp;
        mp[0] = 1;  // empty prefix (even)

        for(int x : arr){
            sum += x;
            int rem = sum % 2;

            if(rem == 1){
                cnt = (cnt + mp[0])%mod; // odd - even
            } else {
                cnt = (cnt +mp[1])%mod;  // even - odd
            }

            mp[rem]++;
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna