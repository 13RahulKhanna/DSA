class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long cand1 = LONG_MIN, cand2 = LONG_MIN;
        long long cnt1 = 0, cnt2 = 0;

        for(auto x : nums) {
            if(x == cand1) {
                cnt1++;
            }
            else if(x == cand2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                cand1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                cand2 = x;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;

        for(auto x : nums) {
            if(x == cand1) cnt1++;
            else if(x == cand2) cnt2++;
        }

        vector<int> ans;

        if(cnt1 > nums.size() / 3)
            ans.push_back(cand1);

        if(cnt2 > nums.size() / 3)
            ans.push_back(cand2);

        return ans;
    }
};