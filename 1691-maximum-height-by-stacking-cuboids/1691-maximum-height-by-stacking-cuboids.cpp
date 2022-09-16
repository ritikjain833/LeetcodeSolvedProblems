class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
            
        }
    //cuboids.push_back({0,0,0});
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        int res=0;
        vector<int> dp(n,0);
        //dp[0]=cuboids[0][2];
        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[j][0]<=cuboids[i][0] and cuboids[j][1]<=cuboids[i][1] and cuboids[j][2]<=cuboids[i][2]){
                    if(dp[i]<dp[j]+cuboids[i][2]){
                        dp[i]=dp[j]+cuboids[i][2];
                    }
                }
                
            }
            res=max(res,dp[i]);
        }
        return res;
        
        
    }
};