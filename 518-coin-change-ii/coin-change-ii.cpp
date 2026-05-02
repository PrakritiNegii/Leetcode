class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();

       vector<long long> prev(amount+1,0), curr(amount+1,0); 
        prev[0] = 1;
        curr[0] = 1;

        for(int i=0; i<n; i++)
         {
          for(int amt=1; amt<=amount; amt++)
           {
            int notTake = 0;
            if(i>0)
              notTake = prev[amt];

            int take = 0;
            if(amt>=coins[i])
               take = curr[amt-coins[i]];

            curr[amt] = (long long) notTake + take;
           }
          prev = curr;
         }

       return (int) prev[amount]; 
    }
};