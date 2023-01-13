class Solution {
public:
    int dfs(int node,vector<vector<int>> &children,string &s,int &longest_path){
        //use the concept of dfs tp find the longest path 
        //find the two longest chain in the subtrees of the current node
        int longest_chain=0;
        int second_chain=0;
        for(auto child : children[node]){
           
            int longest_child=dfs(child,children,s,longest_path);
            //logic for finding the longest and second longest chain
             if(s[node]==s[child]) continue;
            if(longest_child>longest_chain){
                second_chain=longest_chain;
                longest_chain=longest_child;
            }
            else if(longest_child>second_chain){
                second_chain=longest_child;
            }
        }
        //update the longest path to max including the current_node
        longest_path=max(longest_path,longest_chain+second_chain+1);
        //returrn 1+longest_chain because include only one in the return path else it will includes three branches and will not be valid path.
        return 1+longest_chain;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++){
            children[parent[i]].push_back(i);
           // children[i].push_back(parent[i]);
        }
        int longest_path=1;
        dfs(0,children,s,longest_path);
        return longest_path;
    }
};