class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        //sort the array because we only want the count we doesn't care about the acutal number
        sort(nums.begin(),nums.end());
        vector<int> ans;
        //calculate prefix sum of the nums array
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        //for each queries use binary_search of upperbound to find the right most index. and push it onto the an
        for(int i=0;i<queries.size();i++){
            ans.push_back(upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin());
        }
        return ans;
    }
};