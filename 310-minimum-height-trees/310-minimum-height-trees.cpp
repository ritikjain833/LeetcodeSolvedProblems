class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /* use the concept of the diameter of the tree to solve this problem
        
        for finding diameter we can use the concept of topological sort/kahn' s algorithm .
        here we pass one other thing that is remain to find the remaining no of nodes.
        if remain node is even then diameter of the tree is 2*depth +1;
        else remain ==1 then diameter is 2*depth;
        */
        
        vector<int> res;
        //corner case
        if(edges.size()==0){
            return {0};
        }
        
        vector<int> graph[n];
        vector<int> degree(n,0);
        queue<int> q;
        //graph creation and degree calculation
        for(int i=0;i<n-1;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        //pushing the vertex with degree 1
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        int depth=0;
        int remain=n;
        //similar to kahn's algorithm
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
            depth++;
            
        }
        //remaining element present in the queue will be the answer
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
            

        }
        return res;        
        
    }
};