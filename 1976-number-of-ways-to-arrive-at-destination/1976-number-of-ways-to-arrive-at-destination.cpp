#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    
    int mod=1e9+7;
    int dijkstra(vector<vector<pll>> &graph,int n,int src){
        vector<ll> dist(n,LONG_MAX);
        vector<ll> ways(n);
        ways[src]=1;
        dist[src]=0;
        priority_queue<pll,vector<pll>,greater<>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            pll t=pq.top();
            pq.pop();
            ll d=t.first;
            ll u=t.second;
            for(auto [v,time]:graph[u]){
                if(dist[v]>d+time){
                    dist[v]=d+time;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==d+time){
                    ways[v]=(ways[v]+ways[u])%mod;
                }
            }
            
        }
        return ways[n-1];
        
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto &road:roads){
            ll u=road[0];
            ll v=road[1];
            ll time=road[2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        return dijkstra(graph,n,0);
    }
};