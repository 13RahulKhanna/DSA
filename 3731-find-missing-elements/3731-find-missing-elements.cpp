class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto res = minmax_element(nums.begin(), nums.end());
        vector<bool> elem(*res.second - *res.first + 1, false);

        for(auto it : nums){
            elem[it - *res.first] = true;
        }
        
        vector<int> ans;
        for(int i = 0; i < elem.size(); i++){
            if(elem[i] == false) ans.push_back(i + *res.first);
        }
        
        return ans;
    }
};