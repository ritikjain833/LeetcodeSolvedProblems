class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        //Approach is to put + and - in front of the stones. 
        // find the minimum subset difference.
        // use knapsack approach to find the solution.
        // abs(sum(s1)-sum(s2))
        
        int sum1=0;
        int n=stones.size();
        for(int i=0;i<n;i++){
            sum1+=stones[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum1+1,false));
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-stones[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int sum2=sum1/2;
        int ans=INT_MAX;
        // here finding the one subset sum total-2*s1 where dp[i][j] is true
        for(int i=0;i<=sum2;i++){
            if(dp[n][i]==true)
            ans=min(ans,sum1-2*i);
        }
        return ans;
        
    }
};