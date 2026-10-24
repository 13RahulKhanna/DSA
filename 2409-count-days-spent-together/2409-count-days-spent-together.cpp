class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month1 = stoi(arriveAlice.substr(0,2));
        int date1 = stoi(arriveAlice.substr(3));

        int month2 = stoi(arriveBob.substr(0,2));      
        int date2 = stoi(arriveBob.substr(3));

        int month3 = stoi(leaveAlice.substr(0,2));
        int date3 = stoi(leaveAlice.substr(3));

        int month4 = stoi(leaveBob.substr(0,2));      
        int date4 = stoi(leaveBob.substr(3));
        
        vector<int> day = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> pref(13);
        for(int i = 1; i <= 12; i++){
            pref[i] += pref[i - 1] + day[i];
        }
        int arr_alice = pref[month1 - 1] + date1;       
        int dep_alice = pref[month3 - 1] + date3; 

        int arr_bob = pref[month2 - 1] + date2;      
        int dep_bob = pref[month4 - 1] + date4; 

        // cout << arr_alice << " " << arr_bob << " " << dep_alice << " " << dep_bob;
        int start = max(arr_alice, arr_bob);
        int end = min(dep_alice, dep_bob);

        return max(0, end - start + 1);

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna