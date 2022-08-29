class Solution {
public:
    int dx[5]={-1,0,1,0,-1};
    int m;
    int n;
    vector<vector<int>> ans;
    void bfs(vector<vector<int>>& land,int sr,int sc){
        int dr=-1;
        int dc=-1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        land[sr][sc]=0;
        while(!q.empty()){
            pair<int,int> t=q.front();
            q.pop();
            dr=t.first;
            dc=t.second;
            for(int i=0;i<4;i++){
                int nr=dr+dx[i];
                int nc=dc+dx[i+1];
                if(nr>=0 and nr<m and nc>=0 and nc<n and land[nr][nc]==1){
                    land[nr][nc]=0;
                    q.push({nr,nc});
                    
                }
            }
        }
        ans.push_back({sr,sc,dr,dc});
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        //use bfs approach
        m=land.size();
        n=land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    bfs(land,i,j);
                }
            }
        }
        return ans;
        
    }
};