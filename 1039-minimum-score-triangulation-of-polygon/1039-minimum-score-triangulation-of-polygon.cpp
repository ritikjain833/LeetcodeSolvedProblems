class Solution {
public:
    int dp[52][52];
    int solve(vector<int>& values,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            int ans=solve(values,i,k)+solve(values,k+1,j)+values[i-1]*values[j]*values[k];
            if (ans<dp[i][j])
            {
                dp[i][j]=ans;
            }
        }
        return dp[i][j];

    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        int n=values.size();
        return solve(values,1,n-1);
        
    }
};