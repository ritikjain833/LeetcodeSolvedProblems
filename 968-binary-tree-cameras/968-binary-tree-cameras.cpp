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
    int no_of_cameras=0;
    string find_cameras(TreeNode* root){
        if (root==NULL){
            return "ok";
            
        }
        string left=find_cameras(root->left);
        string right=find_cameras(root->right);
        if(left=="want" or right=="want"){
            no_of_cameras++;
            return "provide";
        }
        else if(left=="provide" or right =="provide"){
            return "ok";
            
        }
        else{
            return "want";
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(find_cameras(root)=="want") no_of_cameras++;
        return no_of_cameras;
        
        
        
    }
};