class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0;int j=0;
        int m=version1.length();
        int n=version2.length();
        int n1=0,n2=0;
        while (i<m ||j<n){
          //find decimal equivalent of each number if not equal to .
            while(i<m && version1[i]!='.'){
                n1=n1*10+(version1[i]-'0');
                i++;
            }
            while(j<n && version2[j]!='.'){
                n2=n2*10+(version2[j]-'0');
                j++;
            }
            //cout<<n1<<" "<<n2;
          // compare both of them
            if (n1<n2){
                return -1;
            }
            if(n1>n2){
                return 1;
            }
            //if version1[i] is . or version2[j] is .increment i and j;
            i++;
            j++;
            n1=0,n2=0;
            
            
        }
        return 0;
        
    }
};
