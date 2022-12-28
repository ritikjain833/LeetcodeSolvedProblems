class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
       
        while(k--){
            int t=pq.top();
            pq.pop();
            pq.push(t-t/2);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            //cout<<pq.top()<<endl;
            pq.pop();
        }
        return sum;
        
    }
};