class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;

        for(auto it : nums) mp[it]++;

        if(k == 1){
            int ans = -1;
            for(auto [x, f] : mp)
                if(f == 1) ans = x;
            return ans;
        }

        if(k == nums.size()) return (*mp.rbegin()).first;

        if(mp[*nums.begin()] != 1 && mp[*nums.rbegin()] != 1) return -1;
        if(mp[*nums.begin()] != 1 && mp[*nums.rbegin()] == 1) return *nums.rbegin();
        if(mp[*nums.begin()] == 1 && mp[*nums.rbegin()] != 1) return *nums.begin();

        return max(*nums.begin(), *nums.rbegin());
    }
};