class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //one map is store the counts of each word in words.
        unordered_map<string, int> counts;
        for (string word : words)
        counts[word]++;
        
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
        vector<int> indexes;
        //for loop till n-num*len because concatenation length is num*len and its last index possible is n-num*len
        for (int i = 0; i < n - num * len + 1; i++) 
        {
            //use another unordered_map for checking whether we have seen the current subtring.
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) 
                {
            
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    //is tring is in count increment the frequency in the seen map
                    seen[word]++;
                    // if seen[word] is there we cannot find the answer then
                    if (seen[word] > counts[word])
                    break;
                    }
                //if current word is not in counts skip that position.
            
                else
                    break;
                }
            //if the count of j reaches to words.size then it is possible index.
            if (j == num)
                indexes.push_back(i);
        }
        return indexes;

    }
};