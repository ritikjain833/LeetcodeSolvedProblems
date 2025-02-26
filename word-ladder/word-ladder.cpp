class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // removing duplicates and storing them in set.
        unordered_set<string> word(wordList.begin(),wordList.end());
        //using the concept of bfs to find the shortest transformation subsequence
        queue<string> q;
        //checking if the endword is present in the word or not.
        if (word.find(endWord)==word.end()){
            return 0;
        }
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string f=q.front();
                q.pop();
                //if endword is equal to word return ans
                if (f==endWord){
                    return ans;
                }
                //change each character of the current word with every lowercase character possible.
                for(int j=0;j<f.size();j++){
                    char c=f[j];
                    for(int k=0;k<26;k++){
                        f[j]='a'+k;
                        //if the word is in set push it in the queue and remove from the set.
                        if (word.find(f)!=word.end()){
                            q.push(f);
                            word.erase(f);
                        }
                    }
                    // for next position update prev to the same value.
                    f[j]=c;
                    
                }
            }
            
            ans++;
        }
        return 0;
        
    }
};