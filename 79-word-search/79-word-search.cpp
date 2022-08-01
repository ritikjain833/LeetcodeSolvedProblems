class Solution {
public:
    int m,n;
    int target;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& board,int x,int y,int index, string word,vector<vector<bool>> &visited){
        if(index==target){
            return true;
        }
        if(x<0 or x>=m or y<0 or y>=n or visited[x][y]==true or word[index]!=board[x][y]){
            return false;
        }
        visited[x][y]=true;
        bool res=false;
        for(int i=0;i<4;i++){
            res=res or dfs(board,x+dr[i],y+dc[i],index+1,word,visited);
        }
        visited[x][y]=false;
        return res;
        
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        target=word.length();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,i,j,0,word,visited)==true){
                    return true;
                }
            }
        }
        return false;
        
        
    }
};