class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> mx(n+1);
        vector<int> mn(n+1);
        mx[0] = nums[0];
        mn[n-1] = nums[n-1];
        for(int i = 1;i<n;i++) mx[i] = max(mx[i-1],nums[i]);
        for(int i = n-2;i>=0;i--) mn[i] = min(mn[i+1],nums[i]);
        for(int i = 0;i<n;i++){
            cout << mx[i] << " " << mn[i+1] << endl;
            if(mx[i] - mn[i] <= k) return i;
        }
        return -1;
        
    }
};