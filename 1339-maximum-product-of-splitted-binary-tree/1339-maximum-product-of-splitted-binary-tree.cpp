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
    int mod=1e9+7;
    long long subtree_sum;
    long long total_sum=0;
    long long result=0;
    int tree_sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        subtree_sum=root->val+tree_sum(root->left)+tree_sum(root->right);
        result=max(result,subtree_sum*(total_sum-subtree_sum));
        return subtree_sum;
        
    }
    int maxProduct(TreeNode* root) {
        total_sum=tree_sum(root);
        tree_sum(root);
        return result%mod;
        
    }
};