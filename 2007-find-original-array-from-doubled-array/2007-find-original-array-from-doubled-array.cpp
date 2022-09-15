class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1){
            return {};
        }
        unordered_map<int,int> mp;
        for(auto x:changed){
            mp[x]++;
        }
        vector<int> keys;
        for(auto x:mp){
            keys.push_back(x.first);
            }
        sort(keys.begin(), keys.end());
        vector<int> res;
        for(int x:keys){
            if(mp[x]>mp[2*x]){
                return {};
            }
            for(int i=0;i<mp[x];i++){
                res.push_back(x);
                mp[2*x]--;
            }
        }
        return res;
    }
};