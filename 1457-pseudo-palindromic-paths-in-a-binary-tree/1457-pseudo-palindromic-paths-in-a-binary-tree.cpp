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
    void dfs(TreeNode* root,int path){
        if(root!=NULL){
            //use bit manipulation to set the bit if there is even occurence then it will cancel out and if odd if will because of xor property.
            path=path^(1<<(root->val));
            //if both the child are NULL then check id 
            if(root->left==NULL and root->right==NULL){
                if((path&(path-1))==0){
                    count++;
                }
            }
            else{
                dfs(root->left,path);
                dfs(root->right,path);
            }
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return count;
    }
};