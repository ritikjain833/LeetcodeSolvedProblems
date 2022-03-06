class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int i=2;i<nums.size();i++){
               // 2*b=a+c b-a=c-b             
            if((nums[i-1]-nums[i-2])== (nums[i]-nums[i-1])){
                count+=1;
                ans+=count;
            }
          // subarray arthimetic condition breaks          
            else{
                count=0;
            }
            // cout<<count;
            
        }
        return ans;
        
    }
};
