class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> qu;
        vector<vector<bool>> visit(m,vector(n,false));
        
        if(grid[0][0] == 1 or grid[m-1][n-1] == 1){
            return -1;
        }
        
        qu.push(make_pair(0,0));
        visit[0][0] = true;
        
        while(!qu.empty()){
            int steps = qu.size();
            ans++;
            
            /*directions*/
            for(int i = 0;i < steps; ++i){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                if(x == m-1 and y == n-1){
                    return ans;
                }
                
                for(int j = 0;j < 8; ++j){
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1 >= 0 and x1 < m and y1 >= 0 and y1 < n){
                        if(!visit[x1][y1] and !grid[x1][y1]){
                            qu.push(make_pair(x1,y1));
                            visit[x1][y1] = true;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};