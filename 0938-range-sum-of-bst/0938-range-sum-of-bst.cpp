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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root!=NULL){
        if(root->val>=low and root->val<=high){
            return rangeSumBST(root->left,low,high)+root->val+rangeSumBST(root->right,low,high);
        }
        else if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        else if(root->val>high){
            return rangeSumBST(root->left,low,high);
        }
        else{
            return 0;
        }}
        else{
            return 0;
        }        
    }
};