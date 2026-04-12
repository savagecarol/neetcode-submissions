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
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode*  prev1 = NULL;

        while(curr!=NULL){
            prev = curr;
            curr = curr->next;
            prev->next = prev1;
            prev1 = prev;
        }
        return prev;
        
    }
};
