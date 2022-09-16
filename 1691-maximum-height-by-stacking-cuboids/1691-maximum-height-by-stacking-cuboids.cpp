class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
            
        }
        cuboids.push_back({0,0,0});
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        int res=0;
        vector<int> dp(n,0);
        //dp[0]=cuboids[0][2];
        for(int j=1;j<n;j++){
            dp[j]=cuboids[j][2];
            for(int i=0;i<j;i++){
                if(cuboids[i][0]<=cuboids[j][0] and cuboids[i][1]<=cuboids[j][1] and cuboids[i][2]<=cuboids[j][2]){
                    dp[j]=max(dp[j],dp[i]+cuboids[j][2]);
                    res=max(res,dp[j]);
                }
            }
        }
        return res;
        
        
    }
};