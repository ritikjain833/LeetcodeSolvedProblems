class Solution {
public:
    int minimumDeletions(string s) {
       //Remove all occurences of ba
        stack<char> st;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() and st.top()=='b' and s[i]=='a'){
                count++;
                st.pop();
            }
            else{
                st.push(s[i]);
}
        }
        return count;
    }
};