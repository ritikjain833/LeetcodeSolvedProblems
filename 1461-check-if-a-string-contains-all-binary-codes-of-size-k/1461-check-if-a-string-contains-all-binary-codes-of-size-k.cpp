class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int max_ans=(1<<k);
        vector<int>seen(max_ans,0);
        int val=0;
        int all_one=~max_ans;
        for(int i=0;i<n;i++){
            
            //new_hash = ((old_hash << 1) & all_one) | last_digit_of_new_hash.

            val=(((val<<1)&all_one)|(s[i]-'0'));
            if(i>=k-1 and seen[val]==false){
                seen[val]=true;
                max_ans-=1;
                if(max_ans==0){
                    return true;
                }
            }
        }
        return false;
        
    }
};