// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	stack<int>s;
	void topo_sort(vector<int> adj[],int i,vector<bool> &visited){
	    visited[i]=true;
	    for(auto out:adj[i]){
	        if (visited[out]==false){
	            //visited[out]=true;
	            topo_sort(adj,out,visited);
	        }
	    }
	    s.push(i);
	}
	void reverse_dfs(vector<int> adj[],vector<bool> &visited,int start){
	    visited[start]=true;
	    for(auto out:adj[start]){
	        if(visited[out]==false){
	            //visited[out]=true;
	            reverse_dfs(adj,visited,out);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                topo_sort(adj,i,visited);
            }
        }
        
        vector<int>transpose[V];
        for(int j=0;j<V;j++){
            visited[j]=false;
            for(auto it: adj[j]){
                transpose[it].push_back(j);
            }
        }
        int count=0;
        while(!s.empty()){
            
            int node=s.top();
            s.pop();
            if(visited[node]==false){
                reverse_dfs(transpose,visited,node);
                count++;
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends