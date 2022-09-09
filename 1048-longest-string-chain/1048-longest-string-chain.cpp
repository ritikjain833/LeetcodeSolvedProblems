class Solution {
public:
    bool static compare(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        //sort by length of the string
        sort(words.begin(),words.end(),compare);
        //int res
        int res=1;
        //used to store the string with longest string ending with that.
        unordered_map<string,int> mp;
        for(auto word:words){
            mp[word]=1;
            
            for(int i=0;i<word.size();i++){
                //if after removing a particular character
                //already present in the mp
            string prev=word.substr(0,i)+word.substr(i+1,word.size());
                if(mp.find(prev)!=mp.end()){
                    //mp[current_word]=mp[prev]+1,mp[current_word]
                    mp[word]=max(mp[word],mp[prev]+1);
                    res=max(res,mp[word]);
                }
                }
        }
        return res;
        
    }
};