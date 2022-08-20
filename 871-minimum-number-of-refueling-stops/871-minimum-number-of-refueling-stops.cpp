class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        stations.push_back({target,INT_MAX});
        int ans=0;
        int prev=0;
        for(auto x: stations){
            int location=x[0];
            int capacity=x[1];
            startFuel-=(location-prev);
            while (!pq.empty() and startFuel<0){
                int aux=pq.top();
                pq.pop();
                startFuel+=aux;
                ans+=1;
            }
            if(startFuel<0){
                return -1;
            }
            pq.push(capacity);
            prev=location;
        }
        return ans;
        
        
    }
};