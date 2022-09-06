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
    bool solve(TreeNode* root){
        if(root==NULL){
            return false;
        }
        bool left=solve(root->left);
        bool right=solve(root->right);
        if(left==false){
            root->left=NULL;
        }
        if(right==false){
            root->right=NULL;
        }
        return root->val|| left||right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(solve(root)){
            return root;
        }
        return NULL;
        
    }
};