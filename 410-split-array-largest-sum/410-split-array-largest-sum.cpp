class Solution {
public:
    int minimum_subarray_required(vector<int>& nums,int max_sum_allowed){
        int current_sum=0;
        int splits=0;
        for(auto ele:nums){
            current_sum+=ele;
            if (current_sum>max_sum_allowed){
                splits++;
                current_sum=ele;
                
                    
            }
        }
        return splits+1;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        int max_element=INT_MIN;
        for(auto ele:nums){
            sum+=ele;
            max_element=max(max_element,ele);
                
        }
        int left=max_element;
        int right=sum;
        while (left<right){
            int max_sum_allowed=left+(right-left)/2;
            if(minimum_subarray_required(nums,max_sum_allowed)<=m){
                right=max_sum_allowed;
            }
            else{
                left=max_sum_allowed+1;
            }
        }
        return left;
        
        
    }
};