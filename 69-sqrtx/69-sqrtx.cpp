class Solution {
public:
    int mySqrt(int x) {
        int count=1;
        while (count<=(x/count)){
            count++;
        }
        return count-1;
        
    }
};