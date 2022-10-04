class Solution {
public:
	long long f(int i,vector<vector<int>>& r, vector<int>& st,int m,vector<long long>& dp){
		if(i>=m) return 0;
		if(dp[i]!=-1) return dp[i];
        // Searching for next passenger who can sit  in the car
		int ind=lower_bound(st.begin(),st.end(),r[i][1])-st.begin();
		long long pick=(r[i][1]-r[i][0]+r[i][2])+f(ind,r,st,m,dp);
		long long notpick=f(i+1,r,st,m,dp);
		return dp[i]=max(pick,notpick);
	}

	long long maxTaxiEarnings(int n,vector<vector<int>>& r) {
		int m=r.size();
		sort(r.begin(),r.end());
		vector<int> st;
		for(int i=0;i<m;i++) st.push_back(r[i][0]);
		vector<long long> dp(m,-1);
		return f(0,r,st,m,dp);
	}
};