class NumArray {
    int n = 0;
    vector<int> seg;    
    void build(int index,vector<int> &nums,int l,int r){

        if(l == r) {seg[index] = nums[l];
                    return ;}
        else{
            int mid = (l+r)/2;
            build(2*index + 1,nums,l,mid);
            build(2*index + 2,nums,mid+1,r);
            seg[index] = seg[2*index+1] + seg[2*index+2];
        }
    }
    void helper_update(int data,int i,int index,int l,int r){
        if(i < l || i > r) return;
        if(l == r) seg[index] = data;
        else{
            int mid = (l+r)/2;
            helper_update(data,i,2*index+1,l,mid);
            helper_update(data,i,2*index+2,mid+1,r);
            seg[index] = seg[2*index+1] + seg[2*index+2];
        }
    }
    int query(int index,int l,int r,int ql,int qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return seg[index];
        else{
            int mid = (l+r)/2;
            int left=query(2*index+1,l,mid,ql,qr) ;
                int right= query(2*index+2,mid+1,r,ql,qr);
            return left+right;
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(n*4);
        build(0,nums,0,n-1);
    }
    
    void update(int index, int val) {
        helper_update(val,index,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};