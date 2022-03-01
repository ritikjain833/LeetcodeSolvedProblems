class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i=1;i<=n;i++){
            //eg 5=101 equal to result[5//2]+5%2
            //eg 7=111 equal to first n-1 most significant bits +LSB 
            result[i]=i%2 + result[i>>1];
            
        }
        return result;
        
    }
};
// Time Complexity=O(n)
//Space Complexity=O(n)
