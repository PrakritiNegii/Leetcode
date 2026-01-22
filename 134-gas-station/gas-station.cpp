class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int prevGas = 0;
        int prevCost = 0;

        int totalGas = 0;
        int totalCost = 0;

        int currGas = 0;

        int ansInd = 0;

        for(int i=0; i<n; i++)
         {
          totalGas += gas[i];
          totalCost += cost[i];

          currGas += gas[i];
          if(cost[i]>currGas)
           {
            prevGas = totalGas;
            prevCost = totalCost;
            currGas = 0;
            ansInd = i+1;
           }
          else
           {
            currGas = currGas - cost[i];
           }
         }

        if(ansInd==n) return -1;
        if((currGas+prevGas)>=prevCost) return ansInd;
        return -1;
    }
};