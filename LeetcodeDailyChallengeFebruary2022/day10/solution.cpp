class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //  count is stored to the final answer
        int count=0;
        // sum is used to find the till the current value
        int sums=0;
        // store different sums in the unordered_map or dictionary
        unordered_map<int,int> dict;
        dict[0]=1;
        //intitialize sum of zero to 1
        for(auto x:nums){
            sums+=x;
            // if sums-k is found in dictionary then increas the value of count
            if (dict.find(sums-k)!=dict.end()){
                count+=dict[sums-k];
            }
          // if not found initialize with 1
            if (dict.find(sums)==dict.end()){
                dict[sums]=1;
            // else increment by 1.    
            }
            else 
                dict[sums]+=1;
        }
        return count;
        
    }
};
