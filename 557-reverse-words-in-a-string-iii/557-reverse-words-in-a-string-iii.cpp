class Solution {
public:
    string reverseWords(string s) {
        int last=-1;
        int n=s.size();
        for(int i=0;i<=n;i++){
            if(i==n or s[i]==' '){
                int start=last+1;
                int end=i-1;
                while(start<end){
                    char t=s[start];
                    s[start]=s[end];
                    s[end]=t;
                    start++;
                    end--;
                }
                last=i;
            }
            
        }
        return s;
        
    }
};