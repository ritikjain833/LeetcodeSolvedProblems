class Solution {
public:
    bool solve(vector<int>nums,int target){
        int n=nums.size();
        //vector
        vector<long long> cp;
        for(int i=0;i<n;i++) cp.push_back(nums[i]);
        for(int i=n-1;i>0;i--){
            if(cp[i]>target){
                cp[i-1]+=(cp[i]-target);
            }
            
        }
        if (cp[0]<=target){
            return true;
        }
        return false;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        }
        int r=maxi;
        int ans=0;
        while (l<=r){
            int mid=(l+r)/2;
            if (solve(nums,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};