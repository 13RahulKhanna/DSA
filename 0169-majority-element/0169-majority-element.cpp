class Solution {
public:
    int majorityElement(vector<int>& nums) {        
        long long cand = LONG_MIN, cnt = 0;

        for(auto it : nums){

            if(it != cand){
                cnt--;
                if(cnt < 0){
                    cand = it; cnt = 1;
                }
            }
            else cnt++;

        }

        return cand;
    }
};