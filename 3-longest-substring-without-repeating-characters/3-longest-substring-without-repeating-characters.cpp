class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=i+1;
        if (n==0 || n==1)return n;
        unordered_set<char> temp;
        int ans=0;
        temp.insert(s[0]);
        while (j<n){
            if(temp.find(s[j])==temp.end()){
                temp.insert(s[j]);
                    j++;
                ans=max(ans,j-i);
            }
            else{
                temp.erase(s[i]);
                i++;
                
            }
        }
        return ans;
    }
};