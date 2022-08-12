/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root!=NULL){
        if((root->val>=p->val and q->val>=root->val) or(root->val >=q->val and p->val>=root->val) ){
            return root;
        }
        else if(p->val<root->val and q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else{
            return lowestCommonAncestor(root->right,p,q);
        }
        }
     return NULL;
    }
};