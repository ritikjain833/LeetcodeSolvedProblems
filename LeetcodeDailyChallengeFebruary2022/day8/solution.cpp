class Solution {
public:
    int addDigits(int num) { 
        // if num is zero then return 0
        if (num==0)
            return 0;
        // if sum  of the digits divislbe by 9 number is divisible by 9  then return 9
        else if (num%9==0){
            return 9;
        }
        // if num is not divisible by 9 then return remainder obtained.
        else{
            return num%9;
        }
        
    }
};
