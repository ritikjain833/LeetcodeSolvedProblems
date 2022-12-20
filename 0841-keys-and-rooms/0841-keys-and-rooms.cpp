class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        int count=0;
        while(!q.empty()){
            int t=q.front();
            count++;
            q.pop();
            for(auto x:rooms[t]){
                if(visited[x]==false){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        //cout<<count<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<visited[i]<<" "; 
        // }
        // cout<<endl;
        if(count==n){
            return true;
        }
        return false;
        
    }
};