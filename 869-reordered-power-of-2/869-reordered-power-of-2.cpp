class Solution {
public:
    string sort_digits(int n){
        string digits=to_string(n);
        sort(digits.begin(),digits.end());
        return digits;
    }
    bool reorderedPowerOf2(int n) {
        string target=sort_digits(n);
        for(int i=0;i<31;i++){
            string res=sort_digits(1<<i);
            if(res==target)return true;
            
        }
        return false;
        
    }
};