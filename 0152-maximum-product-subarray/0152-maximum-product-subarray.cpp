class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = nums[0];
        long long prod = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                ans = max(ans, 0LL);
                prod = 1;
                continue;
            }

            prod *= nums[i];
            ans = max(ans, prod);
        }

        prod = 1;

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                prod = 1;
                continue;
            }

            prod *= nums[i];
            ans = max(ans, prod);
        }

        return ans;
    }
};