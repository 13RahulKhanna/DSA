class Solution {
public:
    int check(vector<int>& nums, bool sign){
        int n = nums.size(),ans = 1,local = 1;
        int x = -1;
        if(sign) x = 1;
        for(int i = 1; i < n; i++){
            if(x * nums[i] <= x * nums[i - 1]){
                ans = max(ans, local);
                local = 1;
            }
            else{
                local++;
            }
        }  
        return max(ans, local);     
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        // int n = nums.size(),ans = 1,local = 1;
        // for(int i = 1; i < n; i++){
        //     if(nums[i] <= nums[i - 1]){
        //         ans = max(ans, local);
        //         local = 1;
        //     }
        //     else{
        //         local++;
        //     }
        // }
        int ans = 1;
        ans = max(ans,check(nums,false));
        ans = max(ans, check(nums,true));
        // ans = max(local, ans);
        // local = 1;
        // for(int i = 1; i < n; i++){
        //     if(nums[i] >= nums[i - 1]){
        //         ans = max(ans, local);
        //         local = 1;
        //     }
        //     else{
        //         local++;
        //     }
        // }  
        return ans;      
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna