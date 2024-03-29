class Solution {
public:
    int dp[32][1005];
    int mod=1e9+7;
    int solve(int n,int k,int target){
        if(n==target and n==0){
            return true;
        }
        else if(target<0 or n<0){
            return false;
        }
      
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int res=0;
        for(int i=1;i<=k;i++){
            res+=(solve(n-1,k,target-i));
            res%=mod;
        }
        return dp[n][target]=res;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
        
        
    }
};