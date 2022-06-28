// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution


{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;

    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        cost[0][0]=grid[0][0];
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty()){
            pair<int,pair<int,int>>node=q.top();
            q.pop();
            int x=node.second.first;
            int y=node.second.second;
            for(int i=0;i<4;i++){
                int nr=dr[i]+x;
                int nc=dc[i]+y;
                if(nr>=0 and nr<n and nc>=0 and nc<n and visited[nr][nc]==false and (cost[nr][nc]>node.first+grid[nr][nc])){
                    visited[nr][nc]=true;
                    cost[nr][nc]=node.first+grid[nr][nc];
                    q.push({cost[nr][nc],{nr,nc}});
               
                    
                }
            
            }
        }
        return cost[n-1][n-1]; 
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends