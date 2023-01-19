class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int> right_max(n);
        right_max[n-1]=nums[n-1];
        int suffix_sum=nums[n-1];
        //here we have saved the right_max[i] at each index from i to last
        //using the concept of suffix_sum
        for(int i=n-2;i>=0;i--){
            suffix_sum+=nums[i];
            right_max[i]=max(right_max[i+1],suffix_sum);
        }
        //max_sum stores the max_sum or the normal sum without circular array
        int max_sum=nums[0];
        //special sum stores the max_sum such that some comes from prefix and suffix that are not overlapping
        int special_sum=nums[0];
        //final answer will the maximum of the both
        int prefix_sum=0;
        int cur_max=0;
        for(int i=0;i<n;i++){
            //kadane's algorithm
            cur_max=max(0,cur_max)+nums[i];
            max_sum=max(max_sum,cur_max);
            prefix_sum+=nums[i];
            if(i+1<n){
                
                special_sum=max(special_sum,prefix_sum+right_max[i+1]);
            }
        }
        return max(special_sum,max_sum);
    }
};