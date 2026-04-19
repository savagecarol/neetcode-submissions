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
    
    TreeNode* maker(vector<int>&  pre, int i , int j ,vector<int>&  in, int x ,int y ,   unordered_map<int , int>& m){
        if (i > j || x > y) return NULL;
        TreeNode* root = new TreeNode(pre[i]);
        int value = m[pre[i]];
        int leftSize = value-x;
        root->left = maker(pre,i+1, i + leftSize,in,x,value-1,m);
        root->right = maker(pre, i + leftSize + 1,j,in,value+1,y,m);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int , int> m;
        for(int i = 0 ; i < n ; i++){
               m[inorder[i]] = i;
        }

        return maker(preorder , 0 , n-1 ,  inorder, 0 , n-1, m);
    }
};
