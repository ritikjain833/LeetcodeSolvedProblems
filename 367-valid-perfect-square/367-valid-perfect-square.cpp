class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        int j=num;
        while (i<=j){
            long mid=i+(j-i)/2;
            //cout<<mid;
            if (mid*mid==num){
                return true;
            }
            else if(mid*mid>num){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        
        }
        return false;
        
    }
};