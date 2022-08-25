class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> dict;
        int n=magazine.size();
        for(int i=0;i<n;i++){
            dict[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            dict[ransomNote[i]]--;
            if(dict[ransomNote[i]]<0){
                return false;
            }
        }
        return true;
        
    }
};