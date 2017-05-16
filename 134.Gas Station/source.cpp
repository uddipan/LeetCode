class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(cost.empty())return -1;
        int carry = 0;
        int total = 0;
        int idx = 0;
        for(int i=0; i<gas.size(); i++)
        {
            total += gas[i] - cost[i];
            carry += gas[i] - cost[i];
            if(carry < 0)
            {
                idx = (i+1)%gas.size();
                carry = 0;
            }
        }
        if(total >= 0)
        {
            return idx;
        }
        else
        {
            return -1;
        }
    }
};