class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0){
            return 0;
        }
        sort(points.begin(),points.end(),cmp);
        int count=1;
        int prev=points[0][1];
        for(int i=1;i<n;i++){
            if(prev>=points[i][0]){
                continue;
            }
            else{
                count++;
                prev=points[i][1];
            }
        }
        return count;
        
    }
};