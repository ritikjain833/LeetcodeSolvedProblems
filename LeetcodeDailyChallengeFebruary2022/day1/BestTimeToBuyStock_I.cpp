class Solution {
public
    int maxProfit(vectorint& prices) {
        int n=prices.size();
        int temp=prices[0];
        int profit=0;
        for(int i=1;in;i++){
            temp=min(temp,prices[i]);
            profit=max(profit,prices[i]-temp);
        }
        return profit;
        
    }
};
