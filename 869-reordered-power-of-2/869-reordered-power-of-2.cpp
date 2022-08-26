class Solution {
public:
    
    //function to convert the number to string and store them in sorted order 
    string sort_digits(int n){
        string digits=to_string(n);
        sort(digits.begin(),digits.end());
        return digits;
    }
    bool reorderedPowerOf2(int n) {
        //converted string 
        string target=sort_digits(n);
        for(int i=0;i<31;i++){
            //check for each number i.e. of two. and convert into string and check with target
            string res=sort_digits(1<<i);
            //if found return true
            if(res==target)return true;
            
        }
        //not found
        
        return false;
        
    }
};