class Solution {
public:
    int solve(int i,vector<vector<int>> &jobs,vector<int> &dp,vector<int> &start,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int idx=lower_bound(start.begin(),start.end(),jobs[i][1])-start.begin();
        int select=jobs[i][2]+solve(idx,jobs,dp,start,n);
        int not_select=solve(i+1,jobs,dp,start,n);
        return dp[i]=max(select,not_select);
    }
    int jobScheduling(vector<int>& st,vector<int>& et, vector<int>& profit) {
        int n=st.size();
        vector<vector<int>> jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]={st[i],et[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        vector<int> start;
        for(int i=0;i<n;i++){
            start.push_back(jobs[i][0]);
        }
        vector<int> dp(n,-1);
        return solve(0,jobs,dp,start,n);
        
    }
};