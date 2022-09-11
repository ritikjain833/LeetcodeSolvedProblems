class Solution {
public:
    int seg[4*100005];
    void update(int ind,int low,int high,int idx,int val){
        if(low==high){
            seg[ind]=val;
            return ;
        }
        int mid=(low+high)/2;
        if(idx<=mid){
            update(2*ind+1,low,mid,idx,val);
        }
        else{
            update(2*ind+2,mid+1,high,idx,val);
        }
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    }
      
    int query(int ind,int low,int high,int l,int r){
        if(low>=l and high<=r){
            return seg[ind];}
            if(high<l or low>r){
                return 0;
            }
            int mid=(low+high)/2;
            int left=query(2*ind+1,low,mid,l,r);
            int right=query(2*ind+2,mid+1,high,l,r);
            return max(left,right);
        
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int res=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int left=max(1,nums[i]-k);
            int right=nums[i]-1;
            int q=query(0,0,100005,left,right);
            res=max(res,q+1);
            update(0,0,100005,nums[i],q+1);
            
        }
        return res;
        
    }
};