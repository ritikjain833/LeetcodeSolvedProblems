class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t=minutesToTest/minutesToDie;
        for(int i=0;i<101;i++){
            if (pow(t+1,i)>=buckets){
                return i;
            }
        }
        return -1;
    }
};