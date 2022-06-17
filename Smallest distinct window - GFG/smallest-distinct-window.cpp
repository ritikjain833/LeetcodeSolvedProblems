// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int> mp;
        for(int i=0;i<str.size();i++){
            if (mp.find(str[i])==mp.end()){
                mp.insert({str[i],1});
                
            }
        }
        int n=mp.size();
        unordered_map<char,int> new_map;
        int end=0;
        int start=0;
        int ans=INT_MAX;
        while (end<str.size()){
            if(mp.find(str[end])!=mp.end()){
                new_map[str[end]]++;
            }
            
            while (new_map[str[start]]>1){
                new_map[str[start]]--;
                start++;
            }
            if (new_map.size()==n){
                ans=min(ans,end-start+1);
            }
            end++;
        }
        return ans;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends