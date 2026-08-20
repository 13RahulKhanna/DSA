class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // abs(nums[i] - nums[j]) <= d
        // nums[i] - nums[j] <= d and nums[j] - nums[i] <= d
        // nums[i] - d <= nums[j] and nums[j] <= nums[i] + d
        // nums[i] - d <= nums[j] <= nums[i] + d
        // nums[i] <= nums[j] + d <= nums[i] + 2d
        int n = nums.size();
        set<int> st;

        for(int i = 0; i < n; i++){
            if(i > indexDiff){
                st.erase(nums[i - indexDiff - 1]);
            }
            
            auto it = st.lower_bound(nums[i] - valueDiff);
            if(it != st.end() && *it <= (long long)nums[i] + valueDiff) return true;
            st.insert(nums[i]);

        }
        return false;

    }
};