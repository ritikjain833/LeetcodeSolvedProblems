class Solution {
public:
    int dp[1001][1001] = { 1 };
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        // memset(memo,-1,sizeof(memo));
        // if (n==0){
        //     return 0;
        // }
        // if(k==0){
        //     return 1;
        // }
        // if (memo[n][k]!=-1){
        //     return memo[n][k];
        // }
        // int inv=0;
        // for(int i=0;i<=min(k,n-1);i++){
        //     inv=(inv+kInversePairs(n-1,k-i))%1000000007;
        // }
        // memo[n][k]=inv;
        // return inv;
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=k;j++){
        //         if(j==0){
        //             dp[i][j]=1;
        //         }
        //         else{
        //             for(int x=0;x<=min(j,i-1);x++){
        //                 dp[i][j]=(dp[i][j]+dp[i-1][x])%1000000007;
        //             }
        //         }
        //     }
        // }
        // return dp[n][k];
        
        
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
            }
        return dp[n][k];

                         
        
    }

};