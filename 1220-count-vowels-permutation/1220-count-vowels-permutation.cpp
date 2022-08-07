class Solution {
public:
    int mod=1e9+7;
    int countVowelPermutation(int n) {
        long long a1=1;
        long long e1=1;
        long long i1=1;
        long long o1=1;
        long long u1=1;
        for(int i=1;i<n;i++){
            long long a2=((e1+i1)%mod+u1)%mod;
            long long e2=(a1+i1)%mod;
            long long i2=(e1+o1)%mod;
            long  long o2=(i1)%mod;
            long long u2=(i1+o1)%mod;
            a1=a2;
            e1=e2;
            i1=i2;
            o1=o2;
            u1=u2;
            
                
        }
        return(a1+e1+o1+i1+u1)%mod;
        
    }
};