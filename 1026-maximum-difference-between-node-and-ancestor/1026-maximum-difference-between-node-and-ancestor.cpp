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
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return solve(root,root->val,root->val);
        
    }
    int solve(TreeNode* root,int mx,int mi){
        if(root==NULL){
            return mx-mi;
        }
        mx=max(mx,root->val);
        mi=min(mi,root->val);
        int left=solve(root->left,mx,mi);
        int right=solve(root->right,mx,mi);
        return max(left,right);
    }
};