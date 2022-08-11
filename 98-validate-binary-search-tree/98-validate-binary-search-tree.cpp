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
    TreeNode* prev=NULL;
    // vector<int> ans;
    // void inorder(TreeNode* root){
    //     if(root!=NULL){
    //         inorder(root->left);
    //         ans.push_back(root->val);
    //         inorder(root->right);
    //     }
    // }
    bool validate(TreeNode* root){
        if(root==NULL){
return true;}
        if (!validate(root->left)){
            return false;
        }
        if (prev!=NULL and prev->val>=root->val){
            return false;
        }
        prev=root;
        return validate(root->right);
    }
    bool isValidBST(TreeNode* root) {
//         inorder(root);
//         sort(ans.begin(),ans.end());
        
//         return true;
        return validate(root);
        
        
    }
};