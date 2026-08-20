class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool lst = false, nlst = false;

        for(auto& it : nums)
            it++;

        for(int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);

            if(x == nums.size() + 1)
                lst = true;
            else if(x == nums.size())
                nlst = true;
            else
                nums[x - 1] = -abs(nums[x - 1]);
        }

        if(!lst)
            return nums.size();

        if(!nlst)
            return nums.size() - 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                return i;
        }

        return 0;
    }
};