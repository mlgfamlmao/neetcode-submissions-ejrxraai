class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
     

        ListNode* firstptr = &dummy;
        ListNode* secondptr = head;

        while (n > 0) {
            secondptr = secondptr->next;
            n--;
        }

        while (secondptr != nullptr) {
            firstptr = firstptr->next;
            secondptr = secondptr->next;
        }

        firstptr->next = firstptr->next->next;

        return dummy.next;
    }
};