class Solution {
public:
    long long countCommas(long long n) {
        // 1e3 -> no, 1e6 same, 1e9 double 1e12 triple above that four times
        long long ans = 0;
        long long a = 1e12, b = 1e9, c = 1e6, d = 1e3;
        if(n == 1e15) ans++;
        if(n >= 1e12){ans += (n - a+1)*4;
        n = a-1;
        }
        if(n >= 1e9){ ans += (n - b + 1)*3;
        n = b-1;
        }
        if(n >= 1e6){ans += (n - c+1)*2;
        n = c-1;
        }
        if(n >= 1e3) ans += (n-d+1);
        return ans;

        
    }
};