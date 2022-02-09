class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> dictionary;
        for(int i=0;i<nums.size();i++){
            dictionary[nums[i]]++;
        }
        int count=0;
        for(auto i:dictionary){
            if(k==0){
                if(i.second>=2){
                    count++;
                }}
            else{
                    if(dictionary.find(i.first-k)!=dictionary.end()){
                        count++;
                    }
                    
                
            }
            //cout<<count<<endl;
        }
        //cout<<count;
        return count;
        
    }
};
