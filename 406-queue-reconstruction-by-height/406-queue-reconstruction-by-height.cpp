class Solution {
public:
    static bool cmp(vector<int> &p1,vector<int> &p2){
        if(p1[0]==p2[0]){
            return p1[1]<p2[1];
        }
        return p1[0]>p2[0];
        
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<people.size();i++){
            res.insert(res.begin()+people[i][1],people[i]);
        }
        return res;
    }
};