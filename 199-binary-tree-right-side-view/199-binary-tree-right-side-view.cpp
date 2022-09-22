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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL){
            return res;
        }
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto aux=q.front();
                q.pop();
                if(aux->left){
                    q.push(aux->left);
                }
                if(aux->right){
                    q.push(aux->right);
                }
                if(i==n-1){
                    res.push_back(aux->val);
                }
                
            }
        }
        return res;
        
        
    }
};