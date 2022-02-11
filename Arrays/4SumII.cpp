//https://leetcode.com/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // create a hashmap to store the values
     unordered_map<int,int>ans;
        int count=0;
        //nums1[i]+nums2[j]+nums3[k]+nums4[l]==0 It can be rewritten to
        //nums1[i]+nums2[j]=-(nums3[k]+num3[l])
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                ans[nums1[i]+nums2[j]]+=1;
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                if (ans[-(nums3[i]+nums4[j])]!=0){
                    count+=ans[-(nums3[i]+nums4[j])];
                }
                
                
            }
        }
        return count;
    }
};
