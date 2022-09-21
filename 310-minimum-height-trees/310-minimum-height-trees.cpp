class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(edges.size()==0){
            return {0};
        }
        vector<int> graph[n];
        vector<int> degree(n,0);
        queue<int> q;
        for(int i=0;i<n-1;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        
        int remain=n;
        while(!q.empty() and remain>2){
            int size=q.size();
            for(int i=0;i<size;i++){
                int aux=q.front();
                q.pop();
                degree[aux]--;
                for(auto out: graph[aux]){
                    degree[out]--;
                    if(degree[out]==1){
                        q.push(out);
                    }
                }
            }
            remain-=size;
            
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
            

        }
        return res;        
        
    }
};