class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int i=1;
        while(i<n){
            if(prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
            i++;
        }
        return profit;
        
    }
};