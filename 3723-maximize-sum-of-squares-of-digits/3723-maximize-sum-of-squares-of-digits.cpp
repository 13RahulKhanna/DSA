class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        // a^2 + b^2 + c^2....
        // a0+a1+a2..an = sum
        // 3 25 -> 9 9 6
        // 3 10 -> 9 1 0 -> 8 2 1 -> 64 4 1, 7 3 1 -> 49 9 1
        // 91 -> 82 82 -> 68 73 -> 56 
        int check = sum/9;
        if(sum%9 != 0) check++;
        if(check > num) {cout << "x" << endl; return "";}
         vector<char> v(num,'9'); int curr = num*9,ptr = num-1;
        while(true){
            if(curr == sum) break;
            if(curr-sum >= 9){
                v[ptr] = '0'; curr -= 9; ptr--;
            }
            else{
                v[ptr] = '0' + (9-(curr - sum));
                curr = sum;
            }
        }
        string result = "";
        for(auto it : v) result += it;
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna