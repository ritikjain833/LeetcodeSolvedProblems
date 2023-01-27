class Solution {
public:
    unordered_set<string> st;
    bool dfs(string word){
        for(int len=1;len<word.size();len++){
            string prefix=word.substr(0,len);
            string suffix=word.substr(len,word.length()-len);
            //if both prefix and suffix are present or
            //if prefix is present and remain throuh dfs(suffix)
            if(st.find(prefix)!=st.end() and (st.find(suffix)!=st.end() or dfs(suffix))){
                return true;
            }
            
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto word:words ){
            st.insert(word);
        }
        vector<string> res;
        for(auto word:words){
            if(dfs(word)){
                res.push_back(word);
            }
        }
        return res;
    }
};