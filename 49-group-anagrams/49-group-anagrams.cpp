class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string s:strs){
            string t=s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto p:map){
            ans.push_back(p.second);
        }
        return ans;
    }
};