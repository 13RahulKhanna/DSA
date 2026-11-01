class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i<nums.size(); i++) {
            ans += nums[i] - nums[0];
        }
        return ans;
    }
};


/*

[5,6,8,8,5]
1 2

[6,7,9,8,6]
1. 1 1

[7,8,9,9,7]
1 1. 1

[8,9,9,10,8]
1. 1. 1

[9,10,10,10,9]
1 1

[10,11,10,11,10]
1 1

[11,11,11,12,11]
1

[12,12,12,12,12]
0


[5,6,8]

[6,7,8]

[7,8,8]

[8,8,9]

[9,9,9]



[5,6,8,8]

[6,7,8,9]

[7,8,9,9]

[8,9,9,10]

[9,10,10,10]

[10,11,11,10]

[11,11,11,12]

[12,12,12,12]

1 3 3 3 4
2 4 4 4 4
3 4 5 5 5
4 5 5 6 6
5 6 6 6 7
6 7 7 7 7
7 7 8 8 8
8 8 8 9 9
9 9 9 9 19
19 19 19 19 19
*/

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna