class Solution {
public:
    int dfs(int src,int parent,vector<int> adj[],vector<bool> &hasApple ){
        int total_time=0;
        int child_time=0;
        for(auto child: adj[src]){
            if(child==parent) continue;
            child_time=dfs(child,src,adj,hasApple);
            if(child_time || hasApple[child]) total_time+=(child_time+2);
        }
        return total_time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0,-1,adj,hasApple);
        
    }
};