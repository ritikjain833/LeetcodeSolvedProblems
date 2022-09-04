class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //use the concept of sliding window here
        //here mask is used to store the set bits in the window.
        int mask=0;
        //two pointer approach of sliding window
        int j=0;
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            //if the bit is set so reduce the window
            while(nums[i]&mask){
                //by unsetting that through xor
                mask^=nums[j];
                j++;
            }
            //oring will result in setting the bit
            
            mask|=nums[i];
            //storing the current_max yet
            ans=max(ans,i-j+1);
        }
        return ans;
        
    }
};