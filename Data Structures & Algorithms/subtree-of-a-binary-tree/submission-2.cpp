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
bool traverseBoth(TreeNode* start, TreeNode* end){
    if(start == NULL && end == NULL) return true;
    if(start == NULL || end == NULL) return false;

    return (start->val == end->val) &&
           traverseBoth(start->left , end->left) &&
           traverseBoth(start->right , end->right); 
}

bool traverse(TreeNode* start, TreeNode* end){

    if(start == NULL) return false;
    if(end == NULL) return true;

    if(start->val == end->val && traverseBoth(start, end)){
        return true;
    }

    return traverse(start->left,end) || traverse(start->right , end);
}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            return traverse(root , subRoot);
    }
};
