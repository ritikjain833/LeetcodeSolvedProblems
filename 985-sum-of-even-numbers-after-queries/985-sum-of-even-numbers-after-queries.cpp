class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum=0;
        for(int x:nums){
            if(x%2==0){
                sum+=x;
            }
        }
        int n=nums.size();
        
        vector<int> ans(n,0);
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int ind=queries[i][1];
            if(nums[ind]%2==0){sum-=nums[ind];}
            nums[ind]+=val;
            if(nums[ind]%2==0){sum+=nums[ind];}
            ans[i]=sum;
        }
        return ans;
        
    }
};