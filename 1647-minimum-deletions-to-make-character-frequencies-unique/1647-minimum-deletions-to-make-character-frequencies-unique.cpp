class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(auto x:s){
            mp[x]++;
        }
        vector<int> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        sort(ans.begin(),ans.end());
        int count=0;
        int mini=ans[0];
        unordered_set<int> st;
        st.insert(mini);
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                st.insert(ans[i]);
            }
            else{
                for(int j=ans[i];j>=0;j--){
                    if(j==0){
                        count+=(ans[i]-j);
                        st.insert(j);
                    }
                    if(st.find(j)==st.end()){
                        st.insert(j);
                        count+=(ans[i]-j);
                        break;
                    }
                }
            }
        }
        return count;
        
        
    }
};