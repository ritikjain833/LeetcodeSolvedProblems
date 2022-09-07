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
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string temp=to_string(root->val);
        string left=tree2str(root->left);
        string right=tree2str(root->right);
        //if both are empty return only root-val
        if (left=="" and right==""){
            return temp;
        }
        if(right==""){
            //if right doesn't exist then append left
            return temp+"("+left+")";
        }
        //if left is empty use "()"
        if(left==""){
            return temp+"()"+"("+right+")";
        }
        //if both the children are available then do root->val+add_both children
        return temp+"("+left+")"+"("+right+")";
       
    }
};