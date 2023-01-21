class Solution {
public:
    void backtrack(int start,vector<int> &nums,int n,set<vector<int>> &res,vector<int> &seq){
        //if we have reached the end.
        if(start==n ){
            //and the seq size is more than 1.
            if(seq.size()>=2){
                res.insert(seq);
                
            }
            return;
            
        }
        //if the sequence is empty we can insert element or sequence last is smaller or equal than the next element we can push it.
       
        if(seq.empty() || seq.back()<=nums[start]){
            seq.push_back(nums[start]);
            backtrack(start+1,nums,n,res,seq);
            seq.pop_back();
        }
         //or skip it.
        backtrack(start+1,nums,n,res,seq);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //use the concept of the backtracking here as the constraints is small. 
        //use set to avoid inserting duplicates.
        set<vector<int>> res;
        int n=nums.size();
        vector<int> seq;
        backtrack(0,nums,n,res,seq);
        //convert the result back to vector
        return vector(res.begin(),res.end());
        
    }
};