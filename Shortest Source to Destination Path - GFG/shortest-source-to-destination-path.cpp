// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[X][Y]==0||A[0][0]==0){return -1;}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int x,y,d;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        int count=0;
        bool flag=false;
        A[0][0]=0;
        //bool flag=false;
        while(!q.empty()){
            auto aux=q.front();
            q.pop();
            d=aux.first;
            x=aux.second.first;
            y=aux.second.second;
            if (x==X && y==Y){
                flag=true;
                    break;
                }
            for(int i=0;i<4;i++){
                int nr=dr[i]+x;
                int nc=dc[i]+y;
                
                if(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]==1){
                    q.push({d+1,{nr,nc}});
                    A[nr][nc]=0;
                }
            }
            //count++;
            
        }
        if (flag==true)return d;
        return -1;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends