class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int freq = 1;

        while (right < nums.size()) {

            if (nums[right] == nums[left]) {
                freq++;

                if (freq <= 2) {
                    left++;
                    nums[left] = nums[right];
                }

            }
            else {
                freq = 1;
                left++;
                nums[left] = nums[right];
            }

            right++;
        }

        return left + 1;
    }
};