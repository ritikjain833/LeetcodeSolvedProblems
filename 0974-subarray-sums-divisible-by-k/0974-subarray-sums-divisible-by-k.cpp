//brute force approach to find the subarray sums divisible by k
//calculate the prefix sum and find the pairs i and j so that absolute difference between prefix[i] and prefix[j] is divisible by k;
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int> prefix(n+1,0);
//         for(int i=1;i<=n;i++){
//             prefix[i]=prefix[i-1]+nums[i-1];
//         }
//         int count=0;
//         for(int i=0;i<=n;i++){
//             for(int j=i+1;j<=n;j++){
//                 if(abs(prefix[i]-prefix[j])%k==0){
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };
class Solution{
    public:
    int subarraysDivByK(vector<int> &nums,int k){
        int n=nums.size();
        int prefix_mod=0;
        int res=0;
        vector<int> groups(k);
        groups[0]=1;
        for(int num:nums){
            prefix_mod=(prefix_mod+num%k+k)%k;
            res+=groups[prefix_mod];
            groups[prefix_mod]++;
        }
        return res;
        
    }
};