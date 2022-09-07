class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        int n=costs.size();
        vector<int> diff;
        for(int i=0;i<n;i++){
            sum+=costs[i][1];
            diff.push_back(costs[i][0]-costs[i][1]);
            
            
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n/2;i++){
            sum+=diff[i];
            
        }
        return sum;
        
    }
};