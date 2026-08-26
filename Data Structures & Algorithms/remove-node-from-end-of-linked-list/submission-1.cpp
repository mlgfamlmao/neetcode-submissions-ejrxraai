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