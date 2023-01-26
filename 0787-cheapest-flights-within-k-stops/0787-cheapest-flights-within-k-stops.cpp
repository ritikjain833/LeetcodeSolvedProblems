class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prev(n,1e9);
        prev[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> next=prev;
            for(auto x:flights){
                if(next[x[1]]>prev[x[0]]+x[2]){
                    next[x[1]]=prev[x[0]]+x[2];
                }
            }
            prev=next;
            
        }
        if(prev[dst]!=1e9){
            return prev[dst];
        }
        return -1;
        
    }
};