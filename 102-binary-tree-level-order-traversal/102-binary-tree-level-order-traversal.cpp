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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                auto aux=q.front();
                temp.push_back(aux->val);
                q.pop();
                if(aux->left){
                    q.push(aux->left);
                }
                if(aux->right){
                    q.push(aux->right);
                }
                
            }
            ans.push_back(temp);
        }
        return ans;
    
        
    }
};