/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void good(TreeNode* root , TreeNode* pMax, int& count){
        if(root == NULL) return;
       
        if(pMax->val <= root->val){
             count++;
        }

        good(root->left , (pMax->val>=root->val)? pMax  : root , count);
        good(root->right ,(pMax->val>=root->val)? pMax  : root    , count);
    }



    int goodNodes(TreeNode* root) {
            if(root == NULL) return 0;
            int count = 0;
            good(root , root , count);
            return count;
    }
};
