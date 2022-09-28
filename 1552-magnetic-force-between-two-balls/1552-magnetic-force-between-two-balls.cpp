class Solution {
public:
    
    int solve(vector<int>& positions,int count){
        int ans=1;
        //check difference
        int curr=positions[0];
        for(int i=1;i<positions.size();i++){
            if (positions[i]-curr>=count){
                ans++;
                curr=positions[i];
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& positions, int m) {
        //sort the positions array
        //binary search the target value
        sort(positions.begin(),positions.end());
        int l=0;
        int n=positions.size();
        //max ans possible
        int r=(positions[n-1]-positions[0]);
        int res=0;
        while (l<=r){
            int mid=l+(r-l)/2;
            //if solve returns split more than the desired value we can increase the left
            if(solve(positions,mid)>=m){
                l=mid+1;
                res=mid;
            }
            //decrease the right
            else{
                r=mid-1;
            }
        }
        return res;
        
    }
};