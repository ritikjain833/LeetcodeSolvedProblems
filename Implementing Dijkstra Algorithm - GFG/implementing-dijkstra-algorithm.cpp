// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ans(V,INT_MAX);
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        ans[S]=0;
        q.push({S,0});
        while (!q.empty()){
            pair<int,int> mp=q.top();
            q.pop();
            for (auto out:adj[mp.first]){
                int dist=out[1];
                int next=out[0];
                if (ans[next]>mp.second+dist){
                    ans[next]=mp.second+dist;
                    q.push({next,ans[next]});
                }
            }
            
            
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends