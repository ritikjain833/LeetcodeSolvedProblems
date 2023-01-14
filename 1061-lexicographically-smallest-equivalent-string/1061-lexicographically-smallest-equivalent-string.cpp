class Solution {
public:
    //dfs for component
    void dfs(int node,vector<int> adj[],vector<int> &visited,vector<int> &component,int &mi){
        visited[node]=1;
        component.push_back(node);
        mi=min(mi,node);
       
         for(auto out: adj[node]){
            if(visited[out]==0){
                //cout<<"hello"<<endl;
                dfs(out,adj,visited,component,mi);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //idea is to create a graph between equivalent characters information
        //use the concept of dfs to find the component and from the one component choose the minimum one for smallest string
        vector<int> adj[26];
        int n=s1.size();
       
        for(int i=0;i<n;i++){
           
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
               
        }
        //mapping is used to store the minimum character for each component
        vector<int> mapping(26,0);
        for(int i=0;i<26;i++){
            mapping[i]=i;
        }
        vector<int> visited(26,0);
        for(int c=0;c<26;c++){
            if(visited[c]==0){
                vector<int> component;
                int mi=27;
                dfs(c,adj,visited,component,mi);
                for(int v:component){
                    mapping[v]=mi;
                }
            }
        }
        string ans;
        for(char c:baseStr){
            ans+=(char)(mapping[c-'a']+'a');
        }
        return ans;
        
    }
};