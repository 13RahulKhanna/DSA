class Solution {
public:
    int ans;

    void fn(vector<int>& nums, int target, int k, int i, int j) {
        if(i >= j) return;

        int sum = nums[k] + nums[i] + nums[j];

        if(abs(target - sum) < abs(target - ans))
            ans = sum;

        if(sum == target) return;

        if(sum < target)
            fn(nums, target, k, i + 1, j);
        else
            fn(nums, target, k, i, j - 1);
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; i++) {
            fn(nums, target, i, i + 1, nums.size() - 1);
        }

        return ans;
    }
};