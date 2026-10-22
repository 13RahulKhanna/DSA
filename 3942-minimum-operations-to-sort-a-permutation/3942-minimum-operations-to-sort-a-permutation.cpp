class Solution {
public:

    int minOperations(vector<int>& nums) {

        int n = nums.size();

        if(n <= 1){
            return 0;
        }

        int ans = 1e9;

        int f = 1;

        for(int i = 0; i < n; i++){

            if(nums[i] != (nums[0] + i) % n){
                f = 0;
                break;
            }
        }

        if(f){

            int x = (n - nums[0]) % n;

            ans = min(ans,min(x,n - x + 2));
        }

        f = 1;

        for(int i = 0; i < n; i++){

            int x = (nums[0] - i) % n;

            if(x < 0){
                x += n;
            }

            if(nums[i] != x){
                f = 0;
                break;
            }
        }

        if(f){

            int x = (n - 1 - nums[0] + n) % n;

            ans = min(ans,1 + min(x,n - x));
        }

        return ans == 1e9 ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna