class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //use the concept of silding window and hash table.
        //hash table is used to store the frequencies 
        //right-left+1 will give the window size
        
        int left=0;
        int ans=0;
        unordered_map<int,int> basket;
        int n=fruits.size();
        
        for(int right=0;right<n;right++){
            basket[fruits[right]]++;
            while(basket.size()>2){
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
        
    }
};