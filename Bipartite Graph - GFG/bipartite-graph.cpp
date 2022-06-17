// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int src,vector<int> adj[],vector<int> &color){
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
    bool bfs(int src,vector<int> adj[],vector<int> &color){
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
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //vector<bool> visited(V,False);
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if (color[i]==-1){
	        //bool ans=bfs(i,adj,color);
	        //if (ans==false)return false;}
	        color[i]=1;
	        if (dfs(i,adj,color)==false)return false;
	    }
	    
	    
	}return true;}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends