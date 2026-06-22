class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int nFalse = 0, nTrue = 0;
        int cFalse = 0, cTrue = 0;

        for(int i=n-1; i>=0; i--)
         {
          int take=0, notTake=0;
          //buy
          take = -prices[i] + nTrue;
          notTake = nFalse;
          cFalse = max(take,notTake);
          //sell
          take = prices[i] - fee + nFalse;
          notTake = nTrue;
          cTrue = max(take,notTake);
          
          nFalse = cFalse;
          nTrue = cTrue;
         }

        return nFalse;
    }
};