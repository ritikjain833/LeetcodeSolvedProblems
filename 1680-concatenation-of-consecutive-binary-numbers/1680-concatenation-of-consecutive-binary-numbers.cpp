class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
    
        long mod=1e9+7;
        long len=0;
        for(int i=1;i<=n;i++){
            //if i is power of two change increase the length 
            if((i&(i-1))==0){
                len++;
            }
            //use the left shift operator
            ans=((ans<<len)+i)%mod;
        }
        return ans%mod;
        
    }
};