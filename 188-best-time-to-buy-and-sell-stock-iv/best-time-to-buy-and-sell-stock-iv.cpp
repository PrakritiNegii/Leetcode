class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(k*2+1,0), curr(k*2+1,0);

        for(int i=n-1; i>=0; i--)
         {
          for(int j=k*2-1; j>=0; j--)
           {
            int take = 0, notTake = 0;
            if(j%2==0)
             {
              take = -prices[i] + next[j+1];
              notTake = next[j];
             }
            else
             {
              take = prices[i] + next[j+1];
              notTake = next[j];
             }
            curr[j] = max(take,notTake);
           }
          next = curr;
         }

        return next[0];
    }
};