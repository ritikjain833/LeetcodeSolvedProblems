class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int index=0;
        int n=intervals.size();
        while (index<n and intervals[index][1]<newInterval[0]){
            ans.push_back(intervals[index++]);
            
        }
        while (index<n and intervals[index][0]<=newInterval[1]){
            newInterval[0]=min(intervals[index][0],newInterval[0]);
            newInterval[1]=max(intervals[index][1],newInterval[1]);
            index++;
        }
        ans.push_back(newInterval);
        while (index<n and intervals[index][0]>newInterval[1]){
            ans.push_back(intervals[index++]);
        }    
        return ans;
        
    }
};