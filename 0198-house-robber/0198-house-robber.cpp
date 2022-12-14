class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        if(n==1){
            return nums[0];
        }
        temp[0]=nums[0];
        temp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            temp[i]=max(temp[i-2]+nums[i],temp[i-1]);
        }
        return temp[n-1];
        
    }
};