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
    bool hasCycle(ListNode* head) {
        ListNode* floydTortoise {head};
        ListNode* floydHare {head};
        while (floydHare != nullptr){
              floydTortoise = floydTortoise->next;
              if (floydHare->next == nullptr) return false;
            floydHare = floydHare->next->next;

            
            

            if(floydHare == floydTortoise){
                return true;

            }
          
            
            
        }
        return false;
    }
};
