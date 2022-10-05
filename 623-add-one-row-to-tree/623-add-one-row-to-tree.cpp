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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode* > q;
        q.push(root);
        int current_depth=1;
        while(!q.empty()){
            current_depth++;
            if(current_depth==depth){
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            
        }
        int size=q.size();
        for(int i=0;i<size;i++){
            
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* left=temp->left;
            TreeNode* right=temp->right;
            temp->left=new TreeNode(val);
            temp->left->left=left;
            temp->right=new TreeNode(val);
            temp->right->right=right;
        }
        return root;
        
    }
};