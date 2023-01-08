class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1){
            return 1;
        }
        //From two points there is a line always passing through it.
        int res=2;
        for(int i=0;i<n;i++){
            //use the concept of tan theta or the slope to find points on the same line
            //map to store the angle and the corresponding frequencies.
            unordered_map<double,int> count;
            for(int j=0;j<n;j++){
                if(i!=j){
                    
                    count[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]++;
                }
                
            }
            for( auto [angle,freq]: count){
                res=max(res,freq+1);
            }
        }
        return res;
        
    }
};