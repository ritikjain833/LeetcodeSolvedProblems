class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum1=0;
        vector<int> ans;
        for(auto x:costs){
            sum1+=x[1];
            ans.push_back(x[0]-x[1]);
        }
        int n=costs.size();
        sort(ans.begin(),ans.end());
        for(int i=0;i<n/2;i++)
        {
            sum1+=ans[i];
        }
        return sum1;
        
        
    }
};