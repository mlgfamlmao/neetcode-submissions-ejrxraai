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
    void reorderList(ListNode* head) {
        ListNode* floydTortoise {head};
        ListNode* floydHare {head->next};
        ListNode* nextHalfStart {};

        while (floydHare != nullptr && floydHare->next != nullptr){

            floydTortoise = floydTortoise->next;
            floydHare = floydHare->next->next;

        }

        nextHalfStart = floydTortoise;
        ListNode *current {nextHalfStart->next};
        nextHalfStart->next = nullptr;
        ListNode *prev {nullptr};

        while (current != nullptr){
            ListNode* nextNode{current->next};
            current->next = prev;
            prev = current;
            current= nextNode;
        }

        ListNode* first {head};
        ListNode* second {prev};

        while(second!=nullptr){
            ListNode *temp1 {first->next};
            ListNode *temp2 {second->next};

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;


        }

        



        






        
    }


};
