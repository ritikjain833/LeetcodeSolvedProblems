class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        //use the concept of dynamic programming here.
        //dp[i] := max dollars you can earn ending at i
        vector<vector<pair<int,int>>> vp(n+1);
        vector<long long> dp(n+1,0);
        for(auto x:rides){
            vp[x[1]].push_back({x[0],x[1]-x[0]+x[2]});
        }
        for(int i=1;i<=n;i++){
            //if not ending found at that index
            //we can choose the previous value
            dp[i]=dp[i-1];
            for(auto x:vp[i]){
                dp[i]=max(dp[i],dp[x.first]+x.second);
                
            }
        }
        return dp[n];
        
        
    }
};