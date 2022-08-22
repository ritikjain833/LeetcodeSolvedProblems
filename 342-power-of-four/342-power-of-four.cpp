class Solution {
public:
    bool isPowerOfFour(int n) {
        int x=0;
        while (pow(4,x)<=n){
            if (pow(4,x)==n){
                return true;
            }
            x++;
        }
        return false;
    }
};