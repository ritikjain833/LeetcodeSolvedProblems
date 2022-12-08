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
    vector<int> dfs(TreeNode* root){
       vector<int> temp;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* t=st.top();
            st.pop();
            if(t->right!=NULL){
                st.push(t->right);
            }
            if(t->left!=NULL){
                st.push(t->left);
            }
            if(t->left==NULL and t->right==NULL){
                temp.push_back(t->val);
            }
        }
        return temp;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
        vector<int> f=dfs(root1);
        vector<int> s=dfs(root2);
        int m=f.size();
        int n=s.size();
        //cout<<m<<" "<<n<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<f[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<s[i]<<" ";
        // }
        
        if(m!=n){
            return false;
        }
        else{
            for(int i=0;i<m;i++){
                if(f[i]!=s[i]){
                    //cout<<f[i]<<" "<<s[i]<<endl;
                    return false;
                }
            }
            return true;
        }
        return true;
        
    }
};