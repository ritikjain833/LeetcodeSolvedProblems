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
    //do a post-order traversal because we need to process child first than the node.
    //if we get positive subtree sum we can include to that current node sum else ignore it.
    int max_sum=INT_MIN;
    
    int gainsum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int gain_left=max(gainsum(root->left),0);
        int gain_right=max(gainsum(root->right),0);
        max_sum=max(max_sum,gain_left+gain_right+root->val);
        return max(gain_left+root->val,gain_right+root->val);
    }
    int maxPathSum(TreeNode* root) {
        gainsum(root);
        return max_sum;
    }
};