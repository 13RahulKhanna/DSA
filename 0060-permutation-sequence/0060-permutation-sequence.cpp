class Solution {
public:
    int fac(int n){
        int ans = 1;
        while(n > 0){
            ans *= n;
            n--;
        }
        return ans;
    }

    void edit(vector<int>& ref, int idx){
        ref.erase(ref.begin() + idx);
    }

    string getPermutation(int n, int k) {
        k--; 
        
        vector<int> ref;
        for(int i = 1; i <= n; i++)
            ref.push_back(i);

        string ans = "";

        for(int i = 1; i <= n; i++){

            int block = fac(n - i);

            int idx = k / block;

            ans += to_string(ref[idx]);

            ref.erase(ref.begin() + idx);

            k %= block;
        }

        return ans;
    }
};