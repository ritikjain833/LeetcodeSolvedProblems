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
    int ans=INT_MIN;
    int maxGain(TreeNode* root)
    {   //base case choose 0.
        if(root==NULL)
        return 0;
        //we will use the concept of post-order traversal to solve the problem here.
        //we can choose either maxGain from left or if it's negative we can ignore the value.
        int leftMax=max(maxGain(root->left),0);
        //we can choose either maxGain from right or if it's negative we can ignore the value.
        int rightMax=max(maxGain(root->right),0);
        //calculate ,max including root and left and right
        ans=max(ans,root->val+leftMax+rightMax);
        //we need to return the max of the either upwards.
        return root->val+max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
        

        
    }
};