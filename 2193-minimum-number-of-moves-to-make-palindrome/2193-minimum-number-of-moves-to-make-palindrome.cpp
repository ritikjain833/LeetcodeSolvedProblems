class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        
        //Think of the greedy approach
        //Two pointer approach
        //keep one pointer at left
        //keep one pointer at right
        int result=0;
        int left=0;
        int right=s.length()-1;
        while(left<right){
            //create a copy of the right
            int r=right;
            //perform till s[left]==s[r];
            while(s[left]!=s[r]){
                r--;
            }
            //if the index is same as left then it is odd element and swap with its neightbour and increment the count by 1.
            //don't change the left and right pointer
            if(left==r){
                result++;
                swap(s[r],s[r+1]);
                continue;
            }
            //swap the values and update the result
            while(r<right){
                swap(s[r],s[r+1]);
                result++;
                r++;
            }
            //change the left  and right pointer
            left++;
            right--;
        }
        //return value
        return result;
        
    }
};