class Solution {
public:
    vector<int> dp;
    int n;
    bool solve(vector<int> &nums,int i){
        if(i==n){
            return true;
        }
        if(i>n){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i+1<n and nums[i]==nums[i+1]){
            if(solve(nums,i+2)){
                return true;
            }
            if(i+2<n and nums[i]==nums[i+2]){
                if(solve(nums,i+3)){
                    return true;
                }
            }
        }
        if(i+2<n and nums[i]+1==nums[i+1] and nums[i+1]+1==nums[i+2]){
            if(solve(nums,i+3)){
                return true;
            }
        }
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};