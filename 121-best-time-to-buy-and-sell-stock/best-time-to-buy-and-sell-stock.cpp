class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0, j=1, n=prices.size();
      int maxP = 0;
      while(j<n)
       {
        if(prices[j]<prices[i])
         {
          i=j;
          j=i+1;
         }
        else
         {
          int profit = prices[j] - prices[i];
          maxP = max(profit,maxP);
          j++;
         }
       }
      return maxP;
    }
};