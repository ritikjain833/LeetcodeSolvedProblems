class Solution {
public:
    int n;
    int dp[105];
    
    //we have two choices for each character 
    //1) include single digit
    //2) include 2 digits wtih some restrictions
    //2..... first is 1 and then * or first is 2 and second should lie between 0 and 6.
    int solve(string &s,int start){
        if(start>n){
            return 0;
        }        
        if(s[start]=='0'){
            return 0;
        }
        //if reached then we can get one ans.
        if(start==n){
            return 1;
        }
        //memorization step
        if(dp[start]!=-1){
            return dp[start];
        }
        //first choice
        int res=solve(s,start+1);
        if(start+1<n and( s[start]=='1' || (s[start]=='2' and s[start+1]<'7'))){
            //second choice
            res+=solve(s,start+2);
        }
        return dp[start]=res;
    }
    int numDecodings(string s) {
        if(s.length()==0)return 0;
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
        
    }
};