class Solution {
public:
    int numTilings(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        vector<int> dp(n+1);
        dp[0]=1;
        int mod=1e9+7;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=((2*dp[i-1])%mod+dp[i-3])%mod;
        }
        return dp[n]%mod;
        
        
    }
};