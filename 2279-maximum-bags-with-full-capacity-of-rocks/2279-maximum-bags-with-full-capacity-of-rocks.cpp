class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> remain(n);
        for(int i=0;i<n;i++){
            remain[i]=capacity[i]-rocks[i];
        }
        sort(remain.begin(),remain.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(additionalRocks>=remain[i]){
                additionalRocks-=remain[i];
                count++;
            }
        }
        return count;
    }
};