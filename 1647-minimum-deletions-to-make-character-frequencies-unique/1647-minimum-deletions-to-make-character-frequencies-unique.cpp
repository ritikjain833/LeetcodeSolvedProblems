class Solution {
public:
    int minDeletions(string s) {
        //mp is used to store  the frequencies of each character
        unordered_map<char,int> mp;
        int n=s.length();
        for(auto x:s){
            mp[x]++;
        }
        //ans is used to store the frequencies
        vector<int> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        //sort the frequencies
        sort(ans.begin(),ans.end());
        int count=0;
        int mini=ans[0];
        //used to maintain the number of unique frequencies
        unordered_set<int> st;
        
        st.insert(mini);
        for(int i=1;i<ans.size();i++){
            //if new one found directly add
            if(ans[i]!=ans[i-1]){
                st.insert(ans[i]);
            }
            //iterate from ans[i] to 0
            else{
                for(int j=ans[i];j>=0;j--){
                    //used to handle case like 1 1 1 4
                    //in that case j reaches zero for first but we need to remove third 1 also so add one corner case
                    if(j==0){
                        count+=(ans[i]-j);
                        st.insert(j);
                    }
                    //if not found directly update the count
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