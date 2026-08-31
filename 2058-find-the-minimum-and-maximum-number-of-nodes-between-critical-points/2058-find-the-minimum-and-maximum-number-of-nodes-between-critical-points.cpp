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
        int ptr = 1, first = -1, st = -1, cur = -1, mn = INT_MAX; 

        ListNode* prev = head;
        ListNode* next = head;
        head = head -> next;

        if(!head -> next) return {-1, -1};
        next = head -> next;

        while(next){
            if((head -> val < prev -> val && head -> val < next -> val) || (head -> val > prev -> val && head -> val > next -> val)){
                if(first == -1) first = ptr;

                if(st == -1) st = ptr;               
                else if(cur == -1) cur = ptr;
                else{
                    st = cur;
                    cur = ptr;
                }

                if(cur != -1) mn = min(mn, cur - st);
            }

            prev = head;
            head = next;
            next = next -> next;
            ptr++;
        }

        if(cur == -1) return {-1, -1};
        
        return {mn, cur - first};


    }
};