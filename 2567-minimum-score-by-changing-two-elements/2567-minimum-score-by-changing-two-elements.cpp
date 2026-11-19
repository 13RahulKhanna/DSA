class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // bring extremes closer
        int mn = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
        int mx = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mn){
                mn3 = mn2;
                mn2 = mn;
                mn = nums[i];
            }
            else if(nums[i] < mn2){
                mn3 = mn2;
                mn2 = nums[i];
            }
            else if(nums[i] < mn3){
                mn3 = nums[i];
            }
            if(nums[i] > mx){
                mx3 = mx2;
                mx2 = mx;
                mx = nums[i];
            }
            else if(nums[i] > mx2){
                mx3 = mx2;
                mx2 = nums[i];
            } 
            else if(nums[i] > mx3){
                mx3 = nums[i];
            }          
        }
        
        // cout << mn << endl << mn2 << endl << mx << endl << mx2;
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 3) return 0;
        int ans = INT_MAX;
        ans = min(ans, mx3 - mn);
        ans = min(ans, mx2 - mn2);
        ans = min(ans, mx - mn3);
        return ans;        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna