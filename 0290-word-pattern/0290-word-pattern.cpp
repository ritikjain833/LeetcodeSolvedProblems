class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream iss(s);
        while(iss>>word){
            v.push_back(word);
        }
        set<string> ss;
        if(pattern.size()!=v.size()){
            return false;
        }
        unordered_map<char,string> mp;
        for(int i=0;i<pattern.size();i++){
            char c=pattern[i];
            if(mp.find(c)==mp.end()){
                if(ss.count(v[i])){
                    return false;
                }
                mp[c]=v[i];
                ss.insert(v[i]);
            }
            else{
                if(mp[c]!=v[i]){
                    return false;
                }
            }
            
            
        }
        return true;
        
    }
};