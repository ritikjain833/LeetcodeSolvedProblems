class Solution {
public:
    //use the concept of bfs to find the least number of moves
    //store row,col pair for each count.
    //use dist matrix to store the minimum dist till that.
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> columns(n);
        int count=1;
        vector<pair<int,int>> cells(n*n+1);
        iota(columns.begin(),columns.end(),0);
        for(int row=n-1;row>=0;row--){
            for(int col:columns){
                cells[count++]={row,col};
            }
            reverse(columns.begin(),columns.end());
        }
        queue<int> q;
        vector<int> dist(n*n+1,-1);
        dist[1]=0;
        q.push(1);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int next=cur+1;next<=min(n*n,cur+6);next++){
               
                pair<int,int> p=cells[next];
                int dest;
                if(board[p.first][p.second]!=-1){
                    dest=board[p.first][p.second];
                }
                else{
                    dest=next;
                }
                if(dist[dest]==-1){
                    dist[dest]=dist[cur]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
        
    }
};