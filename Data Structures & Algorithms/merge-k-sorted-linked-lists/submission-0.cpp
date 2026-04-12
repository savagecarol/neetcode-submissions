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

 struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        
        int n = lists.size();

        for(int i = 0 ; i < n ; i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                pq.push(head);
                head = head->next;
            }
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
