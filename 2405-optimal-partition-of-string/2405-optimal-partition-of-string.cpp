class Solution {
public:
    int partitionString(string s) {
       int count=0;
        int n=s.size();
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
            else{
                count++;
                st.clear();
                st.insert(s[i]);
            }
        }
        return ++count;
    }
};