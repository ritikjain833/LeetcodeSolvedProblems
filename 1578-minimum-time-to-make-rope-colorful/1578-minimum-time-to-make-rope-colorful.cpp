class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=colors.length();
        int prev=INT_MAX;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                if(prev==INT_MAX){
                    ans+=min(neededTime[i],neededTime[i-1]);
                    prev=max(neededTime[i],neededTime[i-1]);
                }
                else{
                    ans+=min(neededTime[i],prev);
                    prev=max(neededTime[i],prev);
                }
                }
            else{
                prev=INT_MAX;
                
            }
            
            }
        return ans;
    }
};