class Solution {
public:
    //use the concept of the digit dp.
    //first find the states of the dp.
    // 1)size of the number is 2*1e9 so atmost 11 digits are possible.
    // 2) tight possible two values 0(unrestricted) and 1(restricted).
    // 3)mask highest possible 1111111111=2*10-1 so take 1024.
    int dp[11][2][1024];
    //
    int solve(string &s,int pos=0,int tight=1,int mask=0){
        if(pos==s.size()){
            // mask 00000 (0) should not be counted
            return mask!=0;
        }
        //memorization
        if(dp[pos][tight][mask]!=-1){
            return dp[pos][tight][mask];
        }
        int res=0;
        // case 1 when tight ==1
        
        if(tight==1){
            for(int i=0;i<=s[pos]-'0';i++){
                //if bit is already used continue
                if(mask&(1<<i)) continue;
                
                int new_mask=(mask==0 && i==0?mask:(mask|(1<<i)));
                if(i==s[pos]-'0'){
                    // if reached at the end we are still in tight state and go to next position
                    res+=solve(s,pos+1,1,new_mask);
                }
                else{
                    // if not reached then we can go to unrestriced state and go to next position.
                    res+=solve(s,pos+1,0,new_mask);
                }
            }
            
        }
        
        // case2 when tight==0
        else{
            for(int i=0;i<=9;i++){
                if(mask&(1<<i)) continue;
                int new_mask=(mask==0 && i==0? mask:(mask|(1<<i)));
                res+=solve(s,pos+1,0,new_mask);
            }
        }
        dp[pos][tight][mask]=res;
        return res;
        
    }
    int countSpecialNumbers(int n) {
        string a=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(a);
        
    }
};