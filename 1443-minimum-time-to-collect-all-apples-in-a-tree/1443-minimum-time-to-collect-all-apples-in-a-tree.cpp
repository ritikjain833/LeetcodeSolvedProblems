class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        /* start from the leaves and remove those edges which doesn't contribute in the answer*/
        // use concept of kahn's algorithm
        hasApple[0]=1;
        queue<int>q;
        vector<int> graph[n];
        vector<int> degree(n,0);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
            
        }
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int aux=q.front();
            q.pop();
            if(hasApple[aux]){
                continue;
            }
            for(auto out:graph[aux]){
               
                if(degree[out]>0){
                     degree[out]--;
                degree[aux]--;
                if(degree[out]==1){
                    q.push(out);
                }
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=degree[i];
        }
        return sum;
        
        
    }
};