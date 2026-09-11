class Solution {
public:
    set<pair<int,pair<int,int>>> st;

    void fn(vector<int>& digits, int n, int first, int second, int third){
        if(n == -1){
            if(first != -1 && first != 0 &&
               second != -1 && third != -1 &&
               third % 2 == 0){
                st.insert({first, {second, third}});
            }
            return;
        }

        fn(digits, n - 1, digits[n], second, third);
        fn(digits, n - 1, first, digits[n], third);
        fn(digits, n - 1, first, second, digits[n]);
        fn(digits, n - 1, first, second, third);
    }

    int totalNumbers(vector<int>& digits) {
        st.clear();
        fn(digits, digits.size() - 1, -1, -1, -1);
        return st.size();
    }
};