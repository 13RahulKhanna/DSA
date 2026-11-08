class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        string s3 = "", s4 = "";
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s2[i]){
                if(s3.empty()) continue;
                ans.push_back({s3,s4});
                s3.clear();
                s4.clear();
            }
            else{
                s3 += s1[i];
                s4 += s2[i];
            }
        }
        if(!s3.empty()){
            ans.push_back({s3, s4});
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna