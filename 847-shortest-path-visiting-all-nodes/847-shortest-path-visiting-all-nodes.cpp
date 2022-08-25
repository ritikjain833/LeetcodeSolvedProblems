class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        //if we need to find the shortest path first thing comes in our mind is bfs.but here one node can be visited more than once.
        // so we can use bitmasking to store the current mask
        //if the mask is all ones we are done.
        const int n=graph.size();
        const int visited_all=(1<<n)-1;
        queue<pair<int,int>> q;
        //visited array is of size n*2^n
        vector<vector<int>> visited(n,vector<int>(1<<n));
        //first push the all node with setting their  corresponding bits 
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            
        }
        // do a normal bfs kind of thing here then.
        int steps=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                int state=p.second;
                int node=p.first;
                if (visited[node][state]) continue;
                //stops when conditions is satisfied
                if(state==visited_all){
                    return steps;
                }
                //if already visited.
                
                //mark visited
                visited[node][state]=1;
                //push the adjacent node with seting its bit.
                for(int next:graph[node]){
                    q.push({next,state|(1<<next)});
                }
            }
            steps++;
        }
        return -1;
        
    }
};