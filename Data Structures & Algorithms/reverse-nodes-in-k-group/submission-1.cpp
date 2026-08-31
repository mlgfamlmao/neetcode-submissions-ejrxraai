class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0, head};
        ListNode* traverser{&dummy};

        while (true) {
            ListNode* kth = traverser;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    return dummy.next;
                }
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* current = traverser->next;

            while (current != groupNext) {
                ListNode* next {current->next};
                current->next = prev;
                prev = current;
                current = next;
            }

            ListNode* oldStart {traverser->next};

            traverser->next = kth;
                  traverser = oldStart;

      
        }
    }
};