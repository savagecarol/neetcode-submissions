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


    ListNode* reverse(ListNode* head) {
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
         head = reverse(head);

    ListNode* curr = head;
    ListNode* prev = NULL;
    int i = 1;

    while (curr != NULL) {
        if (i == n) {
            if (prev == NULL) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            } else {
                prev->next = curr->next;
                delete curr;
            }
            break;
        }

        prev = curr;
        curr = curr->next;
        i++;
    }

    head = reverse(head);
    return head;
    }
};
