class Solution {
public:
    int addDigits(int num) {
        int temp=0;
        while(num>0){
            temp+=num%10;
            num=num/10;
            if ((num==0) and temp>9){
                num=temp;
                temp=0;
                    
            }
        }
        return temp;
        
    }
};
