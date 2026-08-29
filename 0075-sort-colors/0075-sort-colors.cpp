class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        for(int i = left; i <= right; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++;
            }
        }
        for(int i = right; i >= left; i--){
            if(nums[i] == 2){
                swap(nums[i], nums[right]);
                right--;
            }
        }

        return;
    }
};