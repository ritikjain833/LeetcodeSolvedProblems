class Solution {
public:
    int arrangeCoins(int n) {
        int left=0;
        int right=n;
        while (left<=right){
            long mid=left+(right-left)/2;
            long curr=mid*(mid+1)/2;
            if (curr==n){
                return mid;
            }
            else if(n<curr){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return right;
        
    }
};