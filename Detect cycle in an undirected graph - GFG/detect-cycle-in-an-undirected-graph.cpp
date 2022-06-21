// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    bool hasCycle(vector<bool> &visited,int src,vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src]=true;
        while (!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto out:adj[node]){
                if (visited[out]==false){
                    visited[out]=true;
                    q.push({out,node});
                }
                else if(visited[out]==true and parent!=out){
                    return true;
                }
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V+1,false);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
            if (hasCycle(visited,i,adj)==true){
                return true;
            }}
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends