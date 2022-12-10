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
    vector<int> temp;
    int mod=1e9+7;
    int subtree_sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans=root->val+subtree_sum(root->left)+subtree_sum(root->right);
        temp.push_back(ans);
        return ans;
    }
    int maxProduct(TreeNode* root) {
        long long  total=subtree_sum(root);
        //cout<<total<<endl;
        long long res=LONG_MIN;
        for(auto x:temp)
        {
            long long aux=(x*(total-x));
            res=max(res,aux);
        }
        return res%mod;
        
    }
};