class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

       
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* start1 = list1;
        ListNode* start2 = list2;

        ListNode* start3;  

        if (list1->val <= list2->val) {
            start3 = list1;
            start1 = start1->next;
        }
        else {
            start3 = list2;
            start2 = start2->next;
        }

        ListNode* start3Head = start3;

        while (start1 != nullptr && start2 != nullptr) {
            if (start1->val <= start2->val) {
                start3->next = start1;
                start1 = start1->next;
            }
            else {
                start3->next = start2;
                start2 = start2->next;
            }

            start3 = start3->next;  
        }

        
        if (start1 != nullptr) {
            start3->next = start1;
        }
        else {
            start3->next = start2;
        }

        return start3Head;
    }
};