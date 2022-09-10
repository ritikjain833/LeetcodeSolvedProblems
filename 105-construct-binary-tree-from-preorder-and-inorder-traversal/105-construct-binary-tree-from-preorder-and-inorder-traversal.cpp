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
    //root element always pointed by index count
    int index=0;
    //mp is used to create a inorder[i] mapping to index based mapping
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int> &preorder,int left,int right){
        if(left>right){
            return NULL;
        }
        //find the rootval
        int root_val=preorder[index++];
        //cout<<root_val<<endl;
        //Create the root node
        TreeNode* root=new TreeNode(root_val);
        //recurse over the left subtree
        root->left=solve(preorder,left,mp[root_val]-1);
        //recurse over the right subtree 
        root->right=solve(preorder,mp[root_val]+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        return solve(preorder,0,preorder.size()-1);
        
        
    }
};