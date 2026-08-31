/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 1 3 2 3 
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ptr = 1; vector<int> points;

        ListNode* prev = head;
        ListNode* next = head;
        head = head -> next;

        if(!head -> next) return {-1, -1};
        next = head -> next;

        while(next){
            if((head -> val < prev -> val && head -> val < next -> val) || (head -> val > prev -> val && head -> val > next -> val)){
                points.push_back(ptr);
            }
            prev = head;
            head = next;
            next = next -> next;
            ptr++;
        }
        if(points.size() < 2) return {-1, -1};
        // for(auto it : points) cout << it << endl;
        int mn = INT_MAX;
        for(int i = 1; i < points.size(); i++){
            mn = min(mn, points[i] - points[i - 1]);
        }

        return {mn, points[points.size() - 1] - points[0]};


    }
};