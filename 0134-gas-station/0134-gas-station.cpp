class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int net_fuel=0;
        for(int i=0;i<n;i++){
            net_fuel+=gas[i]-cost[i];
        }
        if(net_fuel<0){
            return -1;
        }
        net_fuel=0;
        int start=0;
        for(int i=0;i<n;i++){
            int current_fuel=gas[i]-cost[i];
            if (current_fuel+net_fuel<0){
                start=i+1;
                net_fuel=0;
            }
            else{
                net_fuel+=current_fuel;
            }
            
        }
        return start;
        
    }
};