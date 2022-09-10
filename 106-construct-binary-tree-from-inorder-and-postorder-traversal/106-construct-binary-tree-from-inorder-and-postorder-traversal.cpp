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
    int index;
    unordered_map<int,int> mp;
    //incase of post_order do root->right first then root->left;
    TreeNode* solve(vector<int> &postorder,int left,int right){
        if(left>right){
            return NULL;
        }
        int root_val=postorder[index--];
        TreeNode* root=new TreeNode(root_val);
        root->right=solve(postorder,mp[root_val]+1,right);
        root->left=solve(postorder,left,mp[root_val]-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
            
        }
        index=postorder.size()-1;
        return solve(postorder,0,postorder.size()-1);
        
    }
};