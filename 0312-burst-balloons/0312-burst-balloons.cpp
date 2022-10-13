class Solution {
public:
    int dp[305][305];
    int solve(vector<int> &nums,int i,int j){
        if(i>=j){
            return 0;
            
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int mx=INT_MIN;
        for(int k=i;k<j;k++){
            int temp=nums[i-1]*nums[j]*nums[k]+solve(nums,i,k)+solve(nums,k+1,j);
            mx=max(temp,mx);
            
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(nums,1,nums.size()-1);
    }
};