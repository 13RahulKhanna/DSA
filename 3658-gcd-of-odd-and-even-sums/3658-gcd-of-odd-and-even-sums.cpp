class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        // 1 2 3 4 5 6 -> n * ( n + 1) / 2 
        // 1 3 5, 2 4 6 -> 
        
        for(int i = 1; i < 2 * n; i++){
            if(i % 2 == 0) sumEven += i;
            else sumOdd += i;
        }
        return __gcd(sumOdd, sumEven);
    }
};