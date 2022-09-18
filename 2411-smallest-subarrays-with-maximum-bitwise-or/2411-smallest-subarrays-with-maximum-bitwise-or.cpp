class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        /* think of bitwise manipulation when see operator like or,and,xor */
        //here last is used to find the index where bit is set 1 or(that index contribute to the answer)
        int last[30]={};
        int n=nums.size();
        //minimum subarray possible is 1.
        vector<int> res(n,1);
        //iterate from right to left
        for(int i=n-1;i>=0;i--){
            //check for each bit position
            for(int j=0;j<30;j++){
                //if bit is set then mark the last[j]=i to store the index
                if(nums[i]&(1<<j)){
                    last[j]=i;
                }
                //calculate the res using last calculated index and current index length will be last_index -current_index+1
                res[i]=max(res[i],last[j]-i+1);
            }
        }
        //return the answer vector
        return res;
        
    }
};