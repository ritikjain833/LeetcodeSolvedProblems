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
    int count=0;
    void dfs_helper(TreeNode* root,long target){
        if(root!=NULL){
            if(root->val==target){
                count++;
            }
            dfs_helper(root->left,target-root->val);
            dfs_helper(root->right,target-root->val);
        }
    }
    void dfs(TreeNode* root,int target){
        if(root!=NULL){
            dfs_helper(root,target);
            dfs(root->left,target);
            dfs(root->right,target);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return count;
        
    }
};