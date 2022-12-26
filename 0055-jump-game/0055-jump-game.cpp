class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance=0;
        int n=nums.size();
        for(int i=0;i<=distance;i++){
            distance=max(i+nums[i],distance);
            if(distance>=n-1){
                return true;
            }
        }
        return false;
        
    }
};