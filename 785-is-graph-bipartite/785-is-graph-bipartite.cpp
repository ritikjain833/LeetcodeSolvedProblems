class Solution {
public:
    bool dfs(int src,vector<vector<int>> &adj,vector<int> &color){
        vector<int> neighbours=adj[src];
        for(int neighbor:neighbours){
            if (color[neighbor]==color[src]){
                return false;
            }
            else if (color[neighbor]==-1){
                color[neighbor]=1-color[src];
                if (dfs(neighbor,adj,color)==false)return false;
            }
        }
        return true;
    }
     bool bfs(int src,vector<vector<int>> &adj,vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(q.size()!=0){
            int parent=q.front();
            q.pop();
            for(int i=0;i<adj[parent].size();i++){
                int child=adj[parent][i];
                if(color[child]==-1){
                    q.push(child);
                    color[child]=1-color[parent];
                }
                else if(color[child]==color[parent]){
                    return false;
                    
                }
                
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        
         vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if (color[i]==-1){
	        bool ans=bfs(i,graph,color);
	        if (ans==false)return false;}
	        // color[i]=1;
	        // if (dfs(i,graph,color)==false)return false;
	    }
	    
	  return true;  
	
        
    }
};