class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = nums[0], mn = nums[0];

        for(auto it : nums){
            mx = max(mx, it);
            mn = min(mn, it);
        }

        return __gcd(mx, mn);
    }
};