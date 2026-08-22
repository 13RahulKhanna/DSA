class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;        

        int sum = 0, prod = 1;
        while(n > 0){
            sum += n % 10;
            prod *= n % 10;
            n /= 10;
        }

        sum += prod;
        if(x % sum == 0) return true;
        return false;
    }
};