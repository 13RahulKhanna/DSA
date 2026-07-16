class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(),mx = 0;
        vector<int> arr(n,0);
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            arr[i] = __gcd(mx,nums[i]);
        }
        sort(arr.begin(),arr.end());
        long long ans = 0;
        for(int i = 0;i<n/2;i++){
            ans += __gcd(arr[i],arr[n-1-i]);
        }
        return ans;
    }
};