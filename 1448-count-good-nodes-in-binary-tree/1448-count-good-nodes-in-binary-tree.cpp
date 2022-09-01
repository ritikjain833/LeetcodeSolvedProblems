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
    //int count=0;
    int solve(TreeNode* root,int maxi){
        if(root==NULL){
            return 0;
        }
        int res=root->val>=maxi;
        res+=solve(root->left,max(maxi,root->val));
        res+=solve(root->right,max(maxi,root->val));
        return res;
        
        
    }
    int goodNodes(TreeNode* root) {
        
        return solve(root,-100000);
        
    }
};