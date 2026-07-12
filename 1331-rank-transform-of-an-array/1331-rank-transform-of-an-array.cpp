class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({arr[i],i});
        }
        int last = -1, pos = 1, fl = -1;
        vector<int> ans(n,0);

        while(!pq.empty()){
            if(fl == -1){ ans[pq.top().second] = pos; last = pq.top().first; fl = 0;}
            else{
                if(last != pq.top().first){
                    pos++;
                    last = pq.top().first;
                }
                ans[pq.top().second] = pos;
               
            }
             
            cout << pq.top().first;
            pq.pop();
        }
        return ans;
    }
};