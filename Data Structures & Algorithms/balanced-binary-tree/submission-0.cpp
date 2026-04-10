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
    bool ans = true;
    int balance(TreeNode* root){
        if(root == NULL)return 0;
        int left = balance(root->left);
        int right = balance(root->right);
        if(ans && abs(right-left)>1) ans = false; 
        return 1 + max(left , right); 
    }

    bool isBalanced(TreeNode* root) {
        balance(root); 
        return ans;
    }
};
