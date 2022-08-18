class Solution {
struct node
{
    int u,v,wt;//here weight is equal distance given
    
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};
public:
bool static comp(node a,node b)//sort according to distance
{
    return a.wt<b.wt;
}
int findpar(int node, vector<int> &parent)//finding parent using disjoint set
{
    if(node==parent[node])
        return node;
    return findpar(parent[node],parent);
}
void unionn(int u,int v,vector<int> &parent,vector<int> &rank)//union function of disjoint set
{
    u=findpar(u,parent);
    v=findpar(v,parent);
    
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[v]<rank[u])
        parent[v]=u;
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}
int minCostConnectPoints(vector<vector<int>>& points)
{
    vector<node>edges;
    int n=points.size();
    for(int i=0;i<n;i++)//calculating distance between two adjacent points
    {
        for(int j=i+1;j<n;j++)
        {
            int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            edges.push_back(node(i,j,wt));
        }
    }
    sort(edges.begin(),edges.end(),comp);//sort edges according to distances or weights
    
    vector<int> parent(n);
    vector<int> rank(n,0);
    
    for(int i=0;i<n;i++)//Initially every node is parent of itself and rank is 0 for everyone
        parent[i]=i;
    
    int cost=0;
	int count=0;
    for(auto it:edges)
    {
        if(findpar(it.v,parent)!=findpar(it.u,parent))
        {
            cost+=it.wt;//calculating cost
            unionn(it.u,it.v,parent,rank);//to connect we use union operation
            count+=1;
        }
        if(count==n-1){
            return cost;
        }
    }
    return 0;
}
};