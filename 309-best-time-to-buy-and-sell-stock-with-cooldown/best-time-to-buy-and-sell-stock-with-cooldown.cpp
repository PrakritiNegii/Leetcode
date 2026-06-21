class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

       vector<int> next2(2,0), next(2,0), curr(2,0);
       
       for(int i=n-1; i>=0; i--)
        {
         for(int bought=0; bought<=1; bought++)
          {
           int take=0, notTake=0;

           if(!bought)
            {
             take = -prices[i] + next[true];
             notTake = next[false];
            }
           else
            {
             take = prices[i] + next2[false];
             notTake = next[true];
            }

           curr[bought] = max(take,notTake);
          }
         next2 = next;
         next = curr;
        }

       return next[false];
    }
};