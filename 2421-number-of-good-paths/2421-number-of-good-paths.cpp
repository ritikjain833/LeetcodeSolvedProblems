class UnionFind{
    private:
        vector<int> parent,rank;
    public:
        UnionFind(int size){
            parent.resize(size);
            rank.resize(size,0);
            for(int i=0;i<size;i++){
                parent[i]=i;
            }
        }
        int find(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=find(parent[node]);
            
        }
        void union_op(int x,int y){
            x=find(x);
            y=find(y);
            if(rank[x]<rank[y]){
                parent[x]=y;
            }
            else if(rank[x]>rank[y])
            {
                parent[y]=x;
            }
            else{
                parent[y]=x;
                rank[x]++;
            }
        }
    
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //adjacency list representation
        int n=vals.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }
        //creating a map for storing the nodes corresponding to the same value and maintaining order through the increasing order
        map<int,vector<int>> valToNodes;
        for(int node=0;node<n;node++){
            valToNodes[vals[node]].push_back(node);
        }
        UnionFind dsu(n);
        int good_paths=0;
        for(auto& [val,nodes]:valToNodes){
            
            for(int node:nodes){
                for(int neighbour:adj[node]){
                    if(vals[node]>=vals[neighbour]){
                        dsu.union_op(node,neighbour);
                    }
                }
            }
            //iterate over all the nodes in the current valToNodes and increase the size by 1.
            //use the concept of store the nodes with the same parent and increase the size.
            unordered_map<int,int> group;
            for(int u: nodes){
                group[dsu.find(u)]++;
            }
            for(auto& [parent,size]: group){
                good_paths+=(size*(size+1)/2);
            }
            
        }
        return good_paths;
    }
};