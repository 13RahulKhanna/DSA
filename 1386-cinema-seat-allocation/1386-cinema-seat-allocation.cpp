class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        sort(reservedSeats.begin(), reservedSeats.end());
        
        int prev = 1, ans = 0;
        bool fl1 = true, fl2 = true, fl3 = true;
        
        for(auto x : reservedSeats){
            
            if(x[0] != prev){
                
                // finish previous row
                if(fl1) ans++;
                if(fl2) ans++;
                if(!fl1 && !fl2 && fl3) ans++;
                
                // count skipped rows
                ans += (x[0] - prev - 1) * 2;
                
                // reset flags
                fl1 = fl2 = fl3 = true;
                prev = x[0];
            }
            
            int col = x[1];
            
            if(col == 1 || col == 10) continue;
            
            if(col == 2 || col == 3) fl1 = false;
            else if(col == 8 || col == 9) fl2 = false;
            else{
                fl3 = false;
                if(col < 6) fl1 = false;
                else fl2 = false;
            }
        }
        
        // process last row
        if(fl1) ans++;
        if(fl2) ans++;
        if(!fl1 && !fl2 && fl3) ans++;
        
        // rows after last reserved row
        ans += (n - prev) * 2;
        
        return ans;
    }
};