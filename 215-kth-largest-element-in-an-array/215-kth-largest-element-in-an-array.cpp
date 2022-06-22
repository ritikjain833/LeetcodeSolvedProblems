class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
      
        while (k>1){
            q.pop();
            k--;
        }
        return q.top();
        
    }
};