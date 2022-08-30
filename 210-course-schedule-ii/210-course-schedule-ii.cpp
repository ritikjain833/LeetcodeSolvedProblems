class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> degree(numCourses);
        vector<int> adj[numCourses];
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            degree[x[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int aux=q.front();
            q.pop();
            for(auto out:adj[aux]){
                degree[out]--;
                if(degree[out]==0){
                    q.push(out);
                    ans.push_back(out);
                }
            }
        }
        //return ans;
        if(ans.size()==numCourses){
            return ans;
        }
        return {};      
    }
};