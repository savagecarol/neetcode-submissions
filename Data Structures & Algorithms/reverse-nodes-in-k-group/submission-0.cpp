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

    pair<ListNode*,ListNode*>  reverse(ListNode* head){
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* prev1 = NULL;
            while(curr!=NULL){
                prev = curr;
                curr = curr->next;
                prev->next = prev1;
                prev1 = prev;
            }
            return {prev,head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

          ListNode* dummy = new ListNode(0);
          dummy->next = head;
          ListNode* groupPrev = dummy;


            ListNode* curr = head;
            ListNode* start = head;
            int i = 1;

            while(curr!=NULL){
                    if(i == k){
                    ListNode* nextEle = curr->next;
                    curr->next = NULL;
                    pair<ListNode*, ListNode*> value = reverse(start);
                    groupPrev->next = value.first;   // ← fix 1
                    value.second->next = nextEle;
                    groupPrev = value.second;        // ← fix 2
                    start = nextEle;
                    curr = nextEle;                  // ← fix 3
                    i = 1;                           // ← fix 4
                }
                else{
                    i++;
                    curr = curr->next;
                }
            }
            return dummy->next;
    }
};
