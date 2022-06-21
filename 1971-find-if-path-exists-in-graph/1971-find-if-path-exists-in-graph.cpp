class Solution {
public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<int> adj[n];
//         int m=edges.size();
//         for(int i=0;i<m;i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         queue<int> q;
//         q.push(source);
//         vector<bool> visited(n,false);
//         visited[source]=true;
//         while (!q.empty()){
//             int aux=q.front();
//             q.pop();
//             if(aux==destination){
//                 return true;
//             }
//             for(auto out: adj[aux]){
//                 //cout<<out;
//                 if(visited[out]==false){
//                     q.push(out);
//                     visited[out]=true;
//                 }
                
//             }
//         }
//         return false;
        
//     }
    bool dfs(int source,vector<int> adj[],int destination,vector<bool> & visited){
        if (source==destination){
            return true;
        }
        visited[source]=true;
        for(auto out: adj[source]){
            if(visited[out]==false){
                if (dfs(out,adj,destination,visited)==true){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        return dfs(source,adj,destination,visited);
    }
};