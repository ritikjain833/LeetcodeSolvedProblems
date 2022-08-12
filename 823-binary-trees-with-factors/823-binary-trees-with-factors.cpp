class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        //let dp[i] store the number of ways we can to make tree with node i
        //if i has two children lets say x and y then number of ways of dp[i]=dp[x]*dp[y]
        // sort the arr in ascending order.
        //let one of the factor is x and other is arr[i]/x.
        long ans=0;
        long mod=1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int,long> dp;
        for(int i=0;i<arr.size();i++){
            //initializing to 1 because one tree is possible for every value. so single tree with that root node.
            
            dp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    dp[arr[i]]=(dp[arr[i]]+dp[arr[j]]*dp[arr[i]/arr[j]])%mod;
                }
            }
            ans=(ans+dp[arr[i]])%mod;
        }
        return ans;
        
        // Time complexity =O(n^2);
        //Space complexity=O(n);
    }
};