class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        int s=0;
        int n=costs.size();
        for(int i=0;i<n;i++){
           if(s+costs[i]<=coins){
               count++;
               s+=costs[i];
           } 
            else{
                return count;
            }
        }
        return count;
        
    }
};