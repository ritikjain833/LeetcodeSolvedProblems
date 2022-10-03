class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //total time required
        int total=0;
        //store the current maximum in the group
        int current=0;
        int n=colors.length();
        
        for(int i=0;i<n;i++){
            //set it to to zero if differnet group found
            if(i>0 and colors[i]!=colors[i-1]){
                current=0;
            }
            //increment the total by the minimum or smaller one.
            total+=min(current,neededTime[i]);
            //update the current max as the larger one.
            current=max(current,neededTime[i]);
        }
        return total;
    }
};