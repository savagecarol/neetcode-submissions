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

    void traversal(TreeNode* root , TreeNode* parent ,unordered_map<int , pair<TreeNode* ,TreeNode*>> &m){
        if(root==NULL) return;
        m[root->val] = {root , parent};
        traversal(root->left,root,m);
        traversal(root->right,root,m);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int , pair<TreeNode* ,TreeNode*>> m;
        traversal(root , NULL , m);

        int pValue=p->val;
        int qValue=q->val;

        vector<int> x;
        vector<int> y;

        while(m[pValue].second!=NULL){
                x.push_back(pValue);
                pValue = m[pValue].second->val;
        }
        x.push_back(root->val);
                
        while(m[qValue].second!=NULL){
                y.push_back(qValue);
                qValue = m[qValue].second->val;
        }
        y.push_back(root->val);

        for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
             if (x[i] == y[j]) {
                 return m[x[i]].first;
             }
            }
        }


        return root;
    }
};
