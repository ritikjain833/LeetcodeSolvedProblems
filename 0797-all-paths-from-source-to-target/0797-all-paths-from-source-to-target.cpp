class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &res,vector<int> &path, int s,int d ){
        //if source and destination is equal
        if(s==d){
            //add it to the current path 
            path.push_back(d);
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x: graph[s]){
            //next adjacent element in the graph
            path.push_back(s);
            dfs(graph,res,path,x,d);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //use the concept of all paths considering all the possible paths from source to destination
        vector<vector<int>> res;
        vector<int> path;
        int n=graph.size();
        //use the concept of dfs to find the paths
        dfs(graph,res,path,0,n-1);
        return res;
        
    }
};