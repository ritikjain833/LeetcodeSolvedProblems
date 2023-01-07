class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int k=strs[0].size();
        int ans=0;
        for(int col=0;col<k;col++){
            for(int row=1;row<strs.size();row++){
                if(strs[row][col]<strs[row-1][col]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
        
    }
};