class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string f=q.front();
                q.pop();
                if (f==endWord){
                    return ans;
                }
                for(int j=0;j<f.size();j++){
                    char c=f[j];
                    for(int k=0;k<26;k++){
                        f[j]='a'+k;
                        if (word.find(f)!=word.end()){
                            q.push(f);
                            word.erase(f);
                        }
                    }
                    f[j]=c;
                    
                }
            }
            ans++;
        }
        return 0;
        
    }
};