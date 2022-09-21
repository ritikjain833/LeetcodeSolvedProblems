class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {      
        //Instead of finding the maximum score we can find the consective minimum score (subarray) using the concept of prefix sum
        //answer will be total_sum-mini;
        int mini=INT_MIN;
        int n=cardPoints.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+cardPoints[i];
        }
        int total=prefix[n];
        for(int i=0;i<=k;i++){
            mini=max(mini,total-(prefix[i+n-k]-prefix[i]));
            //mini=min(mini,prefix[i+n-k]-prefix[i])
        }
        //return total-mini;
        return mini;
        
    }
};