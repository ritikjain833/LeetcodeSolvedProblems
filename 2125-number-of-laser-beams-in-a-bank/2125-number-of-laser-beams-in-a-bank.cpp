class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ans;
        int res=0;
        int n=bank.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count>0){
                ans.push_back(count);
            }
        }
        int m=ans.size();
        for(int i=0;i<m-1;i++){
            res+=(ans[i]*ans[i+1]);
        }
        return res;
        
        
    }
};