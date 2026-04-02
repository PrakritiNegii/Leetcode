class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<int>> prev(m,vector<int>(3,-1e9));
        
        for(int neutralize=0; neutralize<=2; neutralize++)
         {
          if(coins[0][0]<0 && neutralize>0) 
            prev[0][neutralize] = 0;
          else 
            prev[0][neutralize] = coins[0][0];
         }

        for(int i=0; i<n; i++)
         {
          vector<vector<int>> curr;
          curr=prev;
          for(int j=0; j<m; j++)
           {
            if(i==0 && j==0) continue;

            for(int neutralize=0; neutralize<=2; neutralize++)
             {
              int left = INT_MIN, top = INT_MIN;
              
              if((j-1)>=0) 
                left = coins[i][j] + curr[j-1][neutralize];
              if((i-1)>=0)
                top = coins[i][j] + prev[j][neutralize];

              if(coins[i][j]<0 && neutralize>0)
               {
                int leftN = INT_MIN, topN = INT_MIN;

                if((j-1)>=0) 
                   leftN = curr[j-1][neutralize-1];
                left = max(left,leftN);

                if((i-1)>=0) 
                   topN = prev[j][neutralize-1];
                top = max(top,topN);
               }
              
              curr[j][neutralize] = max(left,top);
             }
           }
          prev = curr;
         }

      return max({prev[m-1][0],prev[m-1][1],prev[m-1][2]});
    }
};