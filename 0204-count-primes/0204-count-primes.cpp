class Solution {
public:
    static vector<int> cnt;
    static bool done;

    void build() {
        if(done) return;
        vector<bool> sieve;

        int N = 1e7;

        sieve.assign(N + 1, true);
        cnt.assign(N + 1, 0);
        sieve[0] = sieve[1] = false;

        for(long long i = 2; i * i <= N; i++) {
            if(!sieve[i]) continue;

            for(long long j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
        for(int i = 2; i < 1e7; i++) {
            cnt[i] = cnt[i - 1] + sieve[i];
        }

        done = true;
    }

    int countPrimes(int n) {
        build();
        if(n <= 2) return 0;

        return cnt[n - 1];
    }
};

vector<int> Solution::cnt;
bool Solution::done = false;