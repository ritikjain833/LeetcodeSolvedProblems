class Solution {
public:
    vector<int> ans;
    void dfs(int rem,int current_num,int k){
        //if rem==0 no more digits can be added simply add the current_num to the ans and return
        if(rem==0){
            ans.push_back(current_num);
            return ;
        }
        //find the last digit of the current_num
        int last_digit=current_num%10;
        //why we need to set because if k==0 then last_digit +0, last_digit-0 both will be same;
        unordered_set<int> st;
        
        st.insert(last_digit+k);
        st.insert(last_digit-k);
        //storing them in temporary vector
        vector<int> temp(st.begin(),st.end());
        for(auto new_digit:temp){
            //if the new_digit formed is lies between 0 and 9
            if(new_digit>=0 and new_digit<=9){
                //new_num will be current_num*10+new_digit;
                int new_num=current_num*10+new_digit;
                //cout<<new_num<<endl;
                //call dfs recursively for the remaining digits and new_num
                dfs(rem-1,new_num,k);
            }
        }  
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        //single digit no consectuive digit is present so return all possible single digit numbers.
        if(n==1){
            vector<int> temp;
            for(int i=0;i<10;i++){
                temp.push_back(i);
            }
            return temp;
        }
        //Now starting digit can be 1 to 9 
        //no remaining digits will be n-1.
        //call dfs for each 
        for(int i=1;i<10;i++){dfs(n-1,i,k);}
        return ans;
        
        
        
    }
};