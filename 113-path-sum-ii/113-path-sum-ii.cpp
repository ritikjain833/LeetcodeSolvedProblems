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
    vector<vector<int>> res;
    void dfs(TreeNode* root,int target,int current,vector<int> &temp){
        if(root!=NULL){
            current+=root->val;
            temp.push_back(root->val);
            if(root->left==NULL and root->right==NULL){
                if(target==current){
                    res.push_back(temp);
                }
            }
            dfs(root->left,target,current,temp);
            dfs(root->right,target,current,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root,targetSum,0,temp);
        return res;
        
    }
};