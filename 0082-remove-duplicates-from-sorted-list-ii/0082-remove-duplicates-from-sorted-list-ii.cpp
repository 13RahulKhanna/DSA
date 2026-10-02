
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev2 = &dummy;

        while (head) {
            ListNode* prev1 = head;

            while (head->next &&
                   head->val == head->next->val) {
                head = head->next;
            }

            if (prev1 != head) {
                ListNode* nxt = head->next;

                prev2->next = nxt;

                while (prev1 != nxt) {
                    ListNode* temp = prev1->next;
                    delete prev1;
                    prev1 = temp;
                }

                head = nxt;
            } else {
                prev2 = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};