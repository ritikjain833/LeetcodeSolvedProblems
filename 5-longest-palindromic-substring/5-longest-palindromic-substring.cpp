class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string ans="";
        int max1=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                bool flag=(s[i]==s[j]);
                if (j-i>=2){
                    dp[i][j]=dp[i+1][j-1] and flag;}
                else{
                    dp[i][j]=flag;
 
                }
                if (dp[i][j] and j-i+1>max1){
                    max1=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
            
        
    }
};