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
    bool validate(TreeNode* root,long mi,long mx){
        if(root==NULL){
return true;}
        if(root->val>=mx || root->val<=mi){
            return false;
        }
        return validate(root->left,mi,root->val) and validate(root->right,root->val,mx);
        
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
        
    }
};