class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ans = INT_MIN;

        for(right; right < nums.size(); right++){
            sum += nums[right];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }

        return ans;
    }
};