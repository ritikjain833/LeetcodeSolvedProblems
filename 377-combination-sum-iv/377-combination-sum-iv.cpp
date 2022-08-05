class Solution {
public:
    int dp[1005];
    
    int solve(vector<int> &nums,int target){
        if(dp[target]!=-1){
            return dp[target];
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i]){
                res+=solve(nums,target-nums[i]);
            }
        }
        dp[target]=res;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        return solve(nums,target);
        
    }
};