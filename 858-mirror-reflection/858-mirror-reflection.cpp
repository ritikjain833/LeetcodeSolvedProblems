class Solution {
public:
    int mirrorReflection(int p, int q) {
        vector<vector<int>> ans;
        ans.push_back({-1,2});
        ans.push_back({0,1});
        int i=1;
        while ((q*i)%p){
            i+=1;
        }
        
        int j=(q*i)/p;
        return ans[i%2][j%2];
    }
};