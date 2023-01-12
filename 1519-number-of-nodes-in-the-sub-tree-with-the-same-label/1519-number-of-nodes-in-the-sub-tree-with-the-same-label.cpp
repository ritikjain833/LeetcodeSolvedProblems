class Solution {
public:
    vector<int> dfs(int src,int parent,vector<vector<int>> &adj,string &labels,vector<int> &ans){
        vector<int> node_count(26);
        node_count[labels[src]-'a']=1;
        for(auto child:adj[src]){
            if(child==parent) continue;
            vector<int> child_count=dfs(child,src,adj,labels,ans);
            for(int i=0;i<26;i++){
                node_count[i]+=child_count[i];
            }
        }
        ans[src]=node_count[labels[src]-'a'];
        return node_count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // graph creation
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n,0);
        dfs(0,-1,adj,labels,ans);
        return ans;
        
    }
};