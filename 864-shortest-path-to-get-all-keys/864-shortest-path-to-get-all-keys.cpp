class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n=m?grid[0].size():0;
    if(!m || !n) return 0;
    int steps=0;
    int count=0;
    vector<int> dirs={0,-1,0,1,0};
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    //here position is stored a combination of both x and y coordinate and i*n+j dividend will give i and remainder will give j    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i*n+j,0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='a' && grid[i][j]<='f') count++; //total alpha number
        }
    }
        int ans=((1<<count)-1);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int curr=q.front().second;
            q.pop();        
            if(curr==ans) return steps; //if all keys hold, just return 
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], new_curr=curr;
                //valid  and wall check
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                // updating the curr with bit position of char
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    new_curr=curr|(1<<(grid[x][y]-'a')); //update hold keys
                }
                // if at that position value is not present  continue
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(curr & (1<<(grid[x][y]-'A')))) continue;
                }
                //if not visited and add it to queue
                if(!visited[x][y][new_curr]){
                    visited[x][y][new_curr]=1;
                    q.push({x*n+y,new_curr});
               }                
            }
        }
        steps++;
    }
    return -1;
}
};