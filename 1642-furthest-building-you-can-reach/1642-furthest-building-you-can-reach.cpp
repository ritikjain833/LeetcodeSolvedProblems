class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int i=0;
        int total_bricks_used=0;
        // use priority queue(max-heap) 
        priority_queue<int> used;
        for(;i<n-1;i++){
            // if heights[i]>=heights[i+1] jump directly
            if (heights[i]>=heights[i+1]){
                continue;
            }
            //calculate the difference of heights 
            // if possible chose bricks greedily and if not possible use ladders
            int diff=heights[i+1]-heights[i];
            if(total_bricks_used+diff<=bricks){
                total_bricks_used+=diff;
                used.push(diff);
                    
                    
            }
            else if(ladders>0){
                // if ladders are there and used is not empty and top of the used is more than diff 
                //remove that from used and add the diff
                // Consider the case 1 5 1 2 3 4 bricks=4 ladder =1
                // now diff is 4 and added to the used 
                if(!used.empty() and used.top()>diff){
                    total_bricks_used=total_bricks_used-used.top()+diff;
                    used.pop();
                    used.push(diff);
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
        
    }
};