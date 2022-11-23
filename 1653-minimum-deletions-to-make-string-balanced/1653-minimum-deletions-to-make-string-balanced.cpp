class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1];
            if(s[i-1]=='b'){
                prefix[i]++;
            }
    
        }
        // for(int i=1;i<=n;i++){
        //     cout<<prefix[i]<<endl;
        // }
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1];
            if(s[i]=='a')
                suffix[i]++;
        }
        // for(int i=0;i<=n;i++){
        //     cout<<suffix[i]<<endl;
        // }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            ans=min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};