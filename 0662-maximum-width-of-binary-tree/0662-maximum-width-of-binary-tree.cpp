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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,unsigned long long>> q;
        if(root==NULL){
            return 0;
        }
        q.push({root,1});
        unsigned long long ans=0;
        while(!q.empty()){
            int n=q.size();
            unsigned long long left=0;
            unsigned long long right=0;
            for(int i=0;i<n;i++){
                auto [aux,ind]=q.front();
                q.pop();
                if(i==0){
                    left=ind;
                }
                if(i==n-1){
                    right=ind;
                }
                if(aux->left!=NULL){
                    q.push({aux->left,2*ind});
                }
                if(aux->right!=NULL){
                    q.push({aux->right,2*ind+1});
                }
                
            }
            ans=max(ans,right-left+1);
}
        return ans;
        
    }
};