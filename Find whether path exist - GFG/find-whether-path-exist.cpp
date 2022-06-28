// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        pair<int,int> src;
        pair<int,int> dest;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==2){
                    dest={i,j};
                }
                else if(grid[i][j]==1){
                    src={i,j};
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        while (!q.empty()){
            pair<int,int>aux=q.front();
            q.pop();
            int x=aux.first;
            int y=aux.second;
            for(int i=0;i<4;i++){
                int nr=dr[i]+x;
                int nc=dc[i]+y;
                if(nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]!=0){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
       
                }
            }
        }
         if(grid[dest.first][dest.second]==0){
            return 1;
            
        }    
        return 0;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends