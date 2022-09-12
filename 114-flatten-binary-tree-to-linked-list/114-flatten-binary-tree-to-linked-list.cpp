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
    // use a previous pointer to maintain the prev node
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root!=NULL){
            // first visit the right child
            //then visit the left child
            flatten(root->right);
            flatten(root->left);
            //make left point to NULL
            
            root->left=NULL;
            //right to prev
            root->right=prev;
            //change prev to root
            prev=root;
        }
        
    }
};
