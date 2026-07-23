class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // 1 2 3 = 0 
        // 1 1 2 = 2
        // 1 2 2 = 1
        // 3 3 3 = 0
        // 1 2 3 4
        // 1 1 0 
        // 1 0 0 1 0 1 1 1 0 
        int n = nums.size();
        if(n<=2) return n;
        if(n==3) return 4;
        int power = 1;
        while(power <= n){
            power *= 2;
        }
        power /= 2;
        return power * 2;
        if(n%2==1){
            cout << n - (n%4);
            return (n - (n%4)) * 2;
        }
        else
            return (n - n%4) * 2;
    }
};