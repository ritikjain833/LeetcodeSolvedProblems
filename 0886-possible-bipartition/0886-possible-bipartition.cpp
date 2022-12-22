class Solution {
public:
    bool bfs(int start,vector<bool> &visited,vector<int> &color,vector<int> adj[]){
        queue<int> q;
        
        color[start]=1;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int aux=q.front();
            q.pop();
            for(auto temp:adj[aux]){
                if(visited[temp]==false){
                    
                    q.push(temp);
                    color[temp]=1-color[aux];
                    visited[temp]=true;
                }
                else {
                    if(color[temp]==color[aux]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        int m=dislikes.size();
        for(int i=0;i<m;i++){
            int x=dislikes[i][0];
            int y=dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n+1,false);
        vector<int> color(n+1);
        
        for(int i=1;i<=n;i++){
            if(visited[i]==false and bfs(i,visited,color,adj)==false){
                return false;
            }
        }
        return true;
        
    }
};