class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1, k = 0;
        ans[i] = nums[k++]; ans[j] = nums[k++];

        while(i < j - 1){
            if(ans[i] > ans[j]){
                ans[++i] = nums[k++];
            }
            else ans[--j] = nums[k++];
        }
        reverse(ans.begin() + j, ans.end());

        return ans;
    }
};