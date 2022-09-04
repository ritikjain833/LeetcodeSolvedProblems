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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto aux=q.front();
            q.pop();
            TreeNode* t=aux.first;
            int r=aux.second.first;
            int c=aux.second.second;
            nodes[c][r].insert(t->val);
            if(t->left){
                q.push({t->left,{r+1,c-1}});
            }
            if(t->right){
                q.push({t->right,{r+1,c+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> cols;
            for(auto s:p.second){
                cols.insert(cols.end(),s.second.begin(),s.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
        
        
    }
};