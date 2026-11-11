class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long seperate_cost = cost1 * need1 + cost2 * need2;            // type1
        long long combined_cost = max(need1, need2) * costBoth;             // type2
        // 5 7

        long long combined_and_seperate_cost = min(need1, need2) * costBoth;
        if(need1 > need2){
            combined_and_seperate_cost += (need1 - need2) * cost1;
        }
        else{
             combined_and_seperate_cost += (need2 - need1) * cost2;
        }                                                                   // type3
        return min(seperate_cost, min(combined_cost, combined_and_seperate_cost));


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna