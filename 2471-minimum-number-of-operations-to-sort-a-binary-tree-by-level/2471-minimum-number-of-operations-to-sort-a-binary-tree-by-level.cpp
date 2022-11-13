/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void swap(vector<int> &arr,
          int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int>arr)
{
  int ans = 0;
    int N=arr.size();
  vector<int>temp = arr;
 
  // Hashmap which stores the
  // indexes of the input array
  map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
    // This is checking whether
    // the current element is
    // at the right place or not
    if (arr[i] != temp[i])
    {
      ans++;
      int init = arr[i];
 
      // If not, swap this element
      // with the index of the
      // element which should come here
      swap(arr, i, h[temp[i]]);
 
      // Update the indexes in
      // the hashmap accordingly
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode* > q;
        int count=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> arr;
            for(int i=0;i<n;i++){
                TreeNode* aux=q.front();
                arr.push_back(aux->val);
                q.pop();
                if(aux->left!=NULL){
                    q.push(aux->left);
                }
                if(aux->right!=NULL){
                    q.push(aux->right);
                }
            }
            int res=minSwaps(arr);
            //cout<<res<<endl;
            count+=res;
            
            
        }
        return count;
    }
};