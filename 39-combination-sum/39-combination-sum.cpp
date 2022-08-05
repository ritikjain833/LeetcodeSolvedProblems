class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candidates,int target,vector<int> & temp,int index,int current_sum){
        if (current_sum>target ||index>candidates.size()){
            return ;
        }
        if(current_sum==target){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            current_sum+=candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates,target,temp,i,current_sum);
            current_sum-=candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        //vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,temp,0,0);
        return ans;
    }
};