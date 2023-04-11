class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res="";
        while(st.size()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};