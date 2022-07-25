class Solution {
public:
    int first_occur(vector<int> &nums,int target){
        int i=0;
        int j=nums.size()-1;
        int index=-1;
        while (i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
            if (nums[mid]==target){
                index=mid;
            }
            
        }
        return index;
    }
    
    int last_occur(vector<int> & nums,int target){
        int i=0;
        int j=nums.size()-1;
        int index=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]<=target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
            if(nums[mid]==target){
                index=mid;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        ans.push_back(first_occur(nums,target));
        ans.push_back(last_occur(nums,target));
        return ans;
        
    }
};