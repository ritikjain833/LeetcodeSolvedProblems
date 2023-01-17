class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        
        //dynamic programming approach 
        //to make a prefix of length i monotone increasing it should also have prefix of length i-1 increasing.
        
        vector<int> dp(n+1);
        //empty string
        dp[0]=0;
        int count=0;
        for(int i=1;i<=n;i++){
            //if s[i-1]==1 we directly append 1 at the last and will use the last answer and will the count the number of ones also
            if(s[i-1]=='1'){
                dp[i]=dp[i-1];
                count++;
            }
            //if s[i-1]==0 we have two choices either to flip it or not.
            //if we flip don't 0 then we have to flip all preceding ones that are present so we maintain the count and will use it.
            //if we flip it we use all the ans of previous case +1 
            else{
                //take the minimum of both the cases
                dp[i]=min(count,dp[i-1]+1);
            }
        }
        //return the final answer
        return dp[n];
    }
};