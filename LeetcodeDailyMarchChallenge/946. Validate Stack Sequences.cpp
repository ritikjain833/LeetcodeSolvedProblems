class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int i=0;
        int j=0;
        vector<int> stack;
        while (i<n){
            stack.push_back(pushed[i]);
            while (stack.size() and stack.back()==popped[j]){
                stack.pop_back();
                j++;
            }
            i++;
            
        }
        if (stack.size()==0){
            return true;
        }
        return false;
            
        
    }
};
