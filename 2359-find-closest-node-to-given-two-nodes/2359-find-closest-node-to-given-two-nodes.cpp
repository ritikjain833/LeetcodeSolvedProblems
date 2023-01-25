class Solution {
public:
    //if the number of outgoing edges is 1 we can do iterative dfs 
    void dfs(int i,int d,vector<int> &edges,vector<int> &memo){
        while(i!=-1 and memo[i]==-1){
            memo[i]=d++;
            i=edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res=-1;
        int dist=INT_MAX;
        vector<int> m1(edges.size(),-1);
        vector<int> m2(edges.size(),-1);
        dfs(node1,0,edges,m1);
        dfs(node2,0,edges,m2);
        for(int i=0;i<edges.size();i++){
            if(min(m1[i],m2[i])>=0 and max(m1[i],m2[i])<dist){
                dist=max(m1[i],m2[i]);
                res=i;
            }
        }
        return res;
        
    }
};