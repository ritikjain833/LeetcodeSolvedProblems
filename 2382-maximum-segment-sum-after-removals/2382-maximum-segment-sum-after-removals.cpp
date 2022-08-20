#define ll long long
/* In the end, we remove all elements from the array (nums.length == removeQueries.length).

So, we can start from no segments, add elements in the reverse (of the removal) order, and create/merge segments.

As we add an element, it can either:

create a new segment (e.g. __, [7], __)
join an existing segment on the left (e.g. 5, 6, [7], __)
join an existing segment on the right (e.g. __, [7], 8, 9)
merge existing segments on the left and right into one (e.g. 5, 6, [7], 8, 9)
*/
class Solution {
public:
    ll parent[100005];
    ll rank[100005];
    ll n; 
    //DSU find_parent 
    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    // DSU union operation
    void Union(int x,int y){
        
        if(rank[x]>=rank[y]){
            rank[x]+=rank[y];
            parent[y]=x;
        }
        else{
            rank[y]+=rank[x];
            parent[x]=y;
        }
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& rq) {
            n=nums.size();
        //makeset initialization in case of the DSU.
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        vector<ll> res(n);
        for(int i=n-1;i>0;i--){
            int index=rq[i];
            int val=nums[index];
            //here rank[x] denotes the sum of the all the elements in the set.
            rank[index]=val;
            // checking the left part
            if(index>0 and rank[index-1]!=0){
                int x=find_parent(index);
                int y=find_parent(index-1);
                Union(x,y);
                
            }
            //checking the right part
            if(index+1<n and rank[index+1]!=0){
                int x=find_parent(index);
                int y=find_parent(index+1);
                Union(x,y);
            }
            int par=find_parent(index);
            //res[i] stores the sum of the current max segment
            res[i-1]=max(res[i],rank[par]);
        }
        return res;
        
        
    }
};