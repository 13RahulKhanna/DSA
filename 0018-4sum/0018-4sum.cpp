class Solution {
public:
    using ll = long long;
    int n;
    vector<vector<int>> ans;

    void fn(vector<int>& nums, int target, int i, int j, int k, int l){
        if(j >= k) return;
        long long sum = ll(nums[i]) + ll(nums[j]) + ll(nums[k]) + ll(nums[l]);
        if(sum == target){
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            int x = nums[j], y = nums[k];

            while(j < k && nums[j] == x) j++;
            while(j < k && nums[k] == y) k--;

            fn(nums, target, i, j, k, l);
            return;
        }

        if(sum < target){
            fn(nums, target, i, j + 1, k, l);
        }
        else 
            fn(nums, target, i, j, k - 1, l);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int l = n - 1; l > i + 2; l--){
                
                if(l < n - 1 && nums[l] == nums[l + 1]) continue;
                fn(nums, target, i, i + 1, l - 1, l);
            }
        }
        return ans;

    }
};