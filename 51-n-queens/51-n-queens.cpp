class Solution {
    public:
    bool safe(int row,int col,vector<string>board,int n){
        int duplicate_row=row;
        int duplicate_col=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=duplicate_row;
        col=duplicate_col;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=duplicate_row;
        col=duplicate_col;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            col--;
            row++;
        }
        return true;
        
    }
    public:
    void solve(int col,vector<string> board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
                    
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        // cout<<s;
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
        
        
    }
};