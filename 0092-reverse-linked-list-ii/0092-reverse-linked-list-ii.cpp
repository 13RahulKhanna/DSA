class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans = head;
        ListNode* prev = nullptr;

        for(int i = 1; i < left; i++) {
            prev = head;
            head = head->next;
        }

        ListNode* before = prev;
        ListNode* leftNode = head;

        ListNode* curr = head;
        ListNode* revPrev = nullptr;

        for(int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        if(before)
            before->next = revPrev;
        else
            ans = revPrev;

        leftNode->next = curr;

        return ans;
    }
};