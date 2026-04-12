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

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* prev1 = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            prev = curr;
            curr = curr->next;
            prev->next = prev1;
            prev1 = prev; 

        }
        return prev;
        
    }


    ListNode* mid(ListNode* head)
    {
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reorderList(ListNode* list1) {

        ListNode* middle = mid(list1);

        ListNode* list2 = reverse(middle->next);
        middle->next = NULL;


        ListNode* first = list1;
        ListNode* second = list2;

        while (second != NULL) {

        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
        }
    }
};
