class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int left = 0, right = 0;

        for(right; right < s.size(); right++){
            if(s[right] == ' '){
                words.push_back(s.substr(left, right - left));
                left = right + 1;
            }
        }

        if(s[right - 1] != ' '){
            words.push_back(s.substr(left, right - left + 1));
        }
        if(words.size() != pattern.size()) return false;

        map<char, string> mp;
        map<string, char> mp2;
        int ptr = 0; 

        for(auto it : pattern){
            if(mp.find(it) != mp.end() && mp[it] != words[ptr]) return false;
            mp[it] = words[ptr++];
        }

        ptr = 0;
        for(auto it : words){
            if(mp2.find(it) != mp2.end() && mp2[it] != pattern[ptr]) return false;
            mp2[it] = pattern[ptr++];
        }
        return true;

    }
};