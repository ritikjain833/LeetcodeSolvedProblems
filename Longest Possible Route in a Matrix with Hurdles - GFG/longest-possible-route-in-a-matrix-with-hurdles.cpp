// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int ans=INT_MIN;
public:
    void backtrack(vector<vector<int>> &matrix,int m,int n,int xs,int ys,int xd,int yd,int current_ans){
        
        if(xs==xd && ys==yd){
                ans=max(ans,current_ans);
                //cout<<ans<<endl;
                return;
        }
        if(xs<0 || xs>=m || ys<0 || ys>=n ||matrix[xs][ys]==0){
            return;
        }
        int temp=matrix[xs][ys];
        matrix[xs][ys]=0;
        backtrack(matrix,m,n,xs+1,ys,xd,yd,current_ans+1);
        backtrack(matrix,m,n,xs-1,ys,xd,yd,current_ans+1);
        backtrack(matrix,m,n,xs,ys+1,xd,yd,current_ans+1);
        backtrack(matrix,m,n,xs,ys-1,xd,yd,current_ans+1);
        matrix[xs][ys]=temp;
        return;
        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        //vector< vector< bool > > visited( m, vector<bool>( n, false ) );
        if (matrix[xd][yd]==0){
            return -1;
        }
        backtrack(matrix,m,n,xs,ys,xd,yd,0);
        //cout<<ans;
        return ans==INT_MIN?-1:ans;
        // code here
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