class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //since the array is sorted remove elements from the corner
        int i=0;
        int j=arr.size()-1;
        //no of elements to be removed
        int remove=arr.size()-k;
        while(remove>0){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                j--;
            }
            else{
                i++;
            }
            remove--;
        }
        //final result
        vector<int> res;
        for(int k=i;k<=j;k++){
            res.push_back(arr[k]);
        }
        return res;
        
    }
};