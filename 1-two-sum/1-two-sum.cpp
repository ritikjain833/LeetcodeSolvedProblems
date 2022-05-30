class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dic;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if (dic.find(temp)!=dic.end()){
                result.push_back(dic[temp]);
                result.push_back(i);
                return result;
            }
            dic[nums[i]]=i;
        }
        return result;
    }
};