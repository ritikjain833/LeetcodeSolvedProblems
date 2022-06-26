// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            set.insert(arr[i]);
        }
        unordered_map<int,int> mp;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while (mp.size()==set.size() and j<=i){
                count+=(n-i);
                mp[arr[j]]--;
                if(mp[arr[j]]==0) mp.erase(arr[j]);
                j++;
            }
        }
        return count;
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends