class Solution {
    /* Example 1 5 1 2 3 4
    where normal logic failed when use greedily bricks then we use the ladder.
    we should use the ladder cautiously because it generate infinite jump and bricks have only h[i+1]-h[i].
    first we use the bricks and latter we have found the some other diff less than the max-heap top so for that we should use bricks and diff should use ladder greedily.
    

    */
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
                // now diff is 4 and added to the used bricks used is 0 and ladder is 1
                // now check diff is 1 is we can use bricks here but we have already used bricks so. we can create a maxheap and take the top element and compare the diff if it is more than that we can use ladder for that latter case and bricks for this case.
                if(!used.empty() and used.top()>diff){
                    //remove the top element from the max-heap
                    total_bricks_used=total_bricks_used-used.top()+diff;
                    used.pop();
                    //insert the diff into the max-heap
                    used.push(diff);
                }
                // and decrease the ladders count by 1.
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
        
    }
};