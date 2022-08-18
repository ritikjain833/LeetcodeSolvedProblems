class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        vector<int> freq;
        for(auto [_,f]: mp){
            freq.push_back(f);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        int half=n/2;
        int count=0;
        for(int i=0;i<n;i++){
            ans+=1;
            count+=freq[i];
            if (count>=half){
                break;
            }
                
        }
        return ans;
        
    }
};