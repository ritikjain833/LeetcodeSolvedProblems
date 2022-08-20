class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // use the concept of max-heap 
        // append the target and maxvalue in the stations vector.
        //logic  go for as possible without refuel and refuel with the maximum yet achieved using the max-heap
        //this way ensures we use minimum no of refuel stops.
        //approach is greedy
        priority_queue<int>pq;
        stations.push_back({target,INT_MAX});
        // store the fuel stops count
        int ans=0;
        // used to calculate the diff of locations between two consecutive stations.
        int prev=0;
        for(auto x: stations){
            int location=x[0];
            int capacity=x[1];
            // update the startfuel with distance travelled
            startFuel-=(location-prev);
            // if startfuel reaches negative then we have to refuel with the max_fuel present in the max-heap
            while (!pq.empty() and startFuel<0){
                int aux=pq.top();
                pq.pop();
                // append the max_fuel till start_fuel reaches non-negative
                
                startFuel+=aux;
                //increment the ans by 1.
                ans+=1;
            }
            //if startfuel reaches negative and pq is empty we cannot move refuel and can't reach the target
            if(startFuel<0){
                return -1;
            }
            // push the current capacity in the pq
            pq.push(capacity);
            //update the previous location
            prev=location;
        }
        return ans;
        //Time complexity=O(n*logn)
        //Space cpmplexity=O(n)
        
        
    }
};