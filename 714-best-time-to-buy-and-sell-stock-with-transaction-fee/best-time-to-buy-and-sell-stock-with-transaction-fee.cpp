class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int nBuy = 0, nSell = 0;
        int cBuy = 0, cSell = 0;

        for(int i=n-1; i>=0; i--)
         {
          int take=0, notTake=0;
          //buy
          take = -prices[i] + nSell;
          notTake = nBuy;
          cBuy = max(take,notTake);
          //sell
          take = prices[i] - fee + nBuy;
          notTake = nSell;
          cSell = max(take,notTake);
          
          nBuy = cBuy;
          nSell = cSell;
         }

        return nBuy;
    }
};