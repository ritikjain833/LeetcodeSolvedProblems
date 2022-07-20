class Solution {
public:
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        for(int i=0;i<expression.length();i++){
            char c=expression[i];
            if(c=='+'|| c=='*'|| c=='-'){
                vector<int> result1=diffWaysToCompute(expression.substr(0,i));
                vector<int> result2=diffWaysToCompute(expression.substr(i+1));
                for(auto n1:result1){
                    for(auto n2:result2){
                        if(c=='+'){
                            result.push_back(n1+n2);
                        }
                        else if(c=='-'){
                            result.push_back(n1-n2);
                        }
                        else{
                            result.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        if (result.empty())
            result.push_back(atoi(expression.c_str()));
        return result;
        //return result;
        
    }
};