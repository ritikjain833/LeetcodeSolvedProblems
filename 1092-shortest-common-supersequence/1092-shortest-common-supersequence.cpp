class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if (str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=m;
        int j=n;
        vector<char> ans;
        while (i>=1 and j>=1){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(j>=1){
            ans.push_back(str2[j-1]);
            j--;
        }
        while(i>=1){
            ans.push_back(str1[i-1]);
            i--;
        }
        // for(auto x:ans){
        //     cout<<x<<" ";
        // }
        string res(ans.rbegin(),ans.rend());
        //string res=str{ans.rbegin(),ans.rend()};
        return res;
    
        
    }
};