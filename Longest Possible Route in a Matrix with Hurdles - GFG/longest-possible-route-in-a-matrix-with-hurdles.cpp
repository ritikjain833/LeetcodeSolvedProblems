// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
 int ans=INT_MIN;
 public:
    int longestPath(vector<vector<int>>&matrix, int xs, int ys, int xd, int yd)
    
    {
        if(!matrix[xd][yd])return -1;
        solve(matrix,xs,ys,xd,yd,0);
        return ans==INT_MIN?-1:ans;
    }
    void solve(vector<vector<int>>&mat,int i,int j,int xd,int yd,int current_ans){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || !mat[i][j])return;
        if(i==xd && j==yd){
            ans=max(ans,current_ans);
            return;
        }
        int temp=mat[i][j];
        mat[i][j]=0;
        solve(mat,i+1,j,xd,yd,current_ans+1);
        solve(mat,i,j+1,xd,yd,current_ans+1);
        solve(mat,i-1,j,xd,yd,current_ans+1);
        solve(mat,i,j-1,xd,yd,current_ans+1);
        mat[i][j]=temp;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends