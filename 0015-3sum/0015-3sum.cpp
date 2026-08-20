class Solution {
public:
    vector<vector<int>> ans;

    void fn(vector<int>& arr, int target,int k, int i, int j){
        if(i >= j || j >= arr.size()) return;     

        if(arr[i] + arr[j] == target){
            ans.push_back({arr[k], arr[i], arr[j]});

            int x = arr[i], y = arr[j];

            while(i < j && arr[i] == x) i++;
            while(i < j && arr[j] == y) j--;

            fn(arr, target, k, i, j);
            return;
        }
        if(arr[i] + arr[j] > target) fn(arr, target, k, i, j - 1);
        else fn(arr, target, k, i + 1, j);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            fn(nums, -nums[i], i, i + 1, nums.size() - 1);
        }
        return ans;
    }
};