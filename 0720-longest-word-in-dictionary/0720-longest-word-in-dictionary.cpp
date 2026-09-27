
class Solution {
public:
    static bool comp(const string& a, const string& b) {
        if (a.size() != b.size())
            return a.size() < b.size();

        return a < b;
    }

    string longestWord(vector<string>& words) {
        map<char, vector<string>> mp;

        for (auto& s : words) {
            mp[s[0]].push_back(s);
        }

        string ans;

        for (auto& [ch, v] : mp) {
            sort(v.begin(), v.end(), comp);

            unordered_set<string> valid;

            for (auto& s : v) {
                if (s.size() == 1 ||
                    valid.count(s.substr(0, s.size() - 1))) {

                    valid.insert(s);

                    if (s.size() > ans.size() ||
                        (s.size() == ans.size() && s < ans)) {
                        ans = s;
                    }
                }
            }
        }

        return ans;
    }
};