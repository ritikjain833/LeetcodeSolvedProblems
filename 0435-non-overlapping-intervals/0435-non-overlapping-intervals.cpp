class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[1]==v2[1]){
            return v1[0]<v2[0];
        }
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),cmp);
        // for(auto x:intervals){
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        int n=intervals.size();
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(end>intervals[i][0]){
                count++;
            }
            else{
                end=intervals[i][1];
            }
        }
        return count;
    }
};