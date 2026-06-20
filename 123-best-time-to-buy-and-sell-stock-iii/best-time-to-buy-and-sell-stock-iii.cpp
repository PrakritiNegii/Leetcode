class Solution {
public:
    int mProfit(vector<int>& prices, int i, bool bought, int count, vector<vector<vector<int>>> &dp)
     {
      if(i>=prices.size()) return 0;
      if(count>=2) return 0;

      if(dp[i][bought][count]!=-1) return dp[i][bought][count];
      
      int take = 0, notTake = 0;
      if(!bought) // not bought then we can buy
       {
        take = -prices[i] + mProfit(prices,i+1,true,count,dp);
        notTake = mProfit(prices,i+1,false,count,dp);
       }
      else //bought then we sell
       {
        take = prices[i] + mProfit(prices,i+1,false,count+1,dp);  
        notTake = mProfit(prices,i+1,true,count,dp);  
       }
      
    //   cout<<"\t"<<take<<"\t"<<notTake<<endl;
      return dp[i][bought][count] = max(take,notTake);
     }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return mProfit(prices,0,false,0,dp);
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//         for(int i=n-1; i>=0; i--)
//          {
//           for(int bought=0; bought<=1; bought++)
//            {
//             for(int count=0; count<2; count++)
//              {
//               int take=0, notTake=0;
//               if(!bought) // not bought then we can buy
//                {
//                 take = -prices[i] + dp[i+1][true][count];
//                 notTake = dp[i+1][false][count];
//                }
//               else //bought then we sell
//                {
//                 take = prices[i] + dp[i+1][false][count];  
//                 notTake = dp[i+1][true][count];  
//                }
//              }
//            }
//          }
//         return dp[0][false][0];
//     }
// };