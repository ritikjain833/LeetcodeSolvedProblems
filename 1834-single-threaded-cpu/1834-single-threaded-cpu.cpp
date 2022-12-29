class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //priority_queue for enqueue time and index
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<vector<int>> stasks;
        int n=tasks.size();
        //stasks for sorting the tasks based on enqueue_time and storing processing time and index
        for(int i=0;i<n;i++){
            stasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(stasks.begin(),stasks.end());
        vector<int> ans;
        //store the current_time as 0
        long long current_time=0;
        //count is used to maintain the index value
        int count=0;
        while(count<n || !pq.empty()){
            if(pq.empty() and current_time<stasks[count][0]){
                current_time=stasks[count][0];
            }
            //push all the taks whose enqueue time is less than or equal to the current_time
            while(count<n and current_time>=stasks[count][0]){
                pq.push({stasks[count][1],stasks[count][2]});
                ++count;
            }
            pair<int,int> p=pq.top();
            pq.pop();
            current_time+=p.first;
            ans.push_back(p.second);
        }
        return ans;
        
    }
};