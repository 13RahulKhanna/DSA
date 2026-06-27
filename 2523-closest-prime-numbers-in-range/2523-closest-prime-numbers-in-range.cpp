class Solution {
public:
    vector<int> sieve(int upperLimit) {
        vector<int> sieve(upperLimit + 1,
                          1);

        sieve[0] = 0;
        sieve[1] = 0;

        for (int number = 2; number * number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                for (int multiple = number * number; multiple <= upperLimit;
                     multiple += number) {
                    sieve[multiple] = 0;
                }
            }
        }
        return sieve;
    }
    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right; vector<int> sieveArray = sieve(upperLimit); vector<int> prime;

        for(int num = left;num <= right; num++)
            if(sieveArray[num] == 1) prime.push_back(num);

        if(prime.size() < 2) return {-1,-1};

        vector<int> closestPrime(2,-1); int distance = INT_MAX;
        for(int i = 0;i<prime.size()-1;i++){
            if(prime[i+1] - prime[i] < distance){
                closestPrime = {prime[i],prime[i+1]};
                distance = prime[i+1] - prime[i];
            }
        }

        return closestPrime;
    }
};