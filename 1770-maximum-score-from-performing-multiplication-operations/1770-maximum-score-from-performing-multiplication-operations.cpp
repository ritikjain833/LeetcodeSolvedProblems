//Top Down approach
// class Solution {
// public:
//     int m,n;
//     //we can convert dp of three states to (left,right,i) to dp of two states (left,i);
//     //we can right to =n-1-(i-l);
//     //right=n-1-i+l;
//     //we can also find that left we can move till m steps so create dp of m*m .
//     int dp[1005][1005];
//     int solve(vector<int> &nums,vector<int> &multipliers,int left,int i){
//         if(i==m){
//             return 0;
//         }
//         if(dp[left][i]!=-1){
//             return dp[left][i];
//         }
//         //l corresponds to left side picking
//         int l=solve(nums,multipliers,left+1,i+1)+multipliers[i]*nums[left];
//         //r corresponds to right side picking 
//         int r=solve(nums,multipliers,left,i+1)+multipliers[i]*nums[n-1-(i-left)];
//         //return  max of both
//         return dp[left][i]=max(l,r);
//     }
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         n=nums.size();
//         m=multipliers.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(nums,multipliers,0,0);
        
//     }
// };
//Bottom-up approach.
class Solution{
    public:
    int maximumScore(vector<int> &nums,vector<int>& multipliers){
        int m=multipliers.size();
        int n=nums.size();
        int dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int op=m-1;op>=0;op--){
            for(int left=op;left>=0;left--){
                int l=multipliers[op]*nums[left]+dp[op+1][left+1];
                int r=multipliers[op]*nums[n-1-(op-left)]+dp[op+1][left];
                dp[op][left]=max(l,r);
               
            }
        }
        return dp[0][0]; 
    }
    
};