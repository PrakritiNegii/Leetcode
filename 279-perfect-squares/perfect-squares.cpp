class Solution {
public:
    bool isPerfectSquare(int n)
     {
      int sqroot = (int) sqrt(n);
      return (sqroot*sqroot == n);
     }

    int numSquares(int n) {
       vector<int> dp(n+1,1e8);

       dp[0] = 0;
       // dp[i] = minimum squares to form i
       for(int i=1; i<=n; i++)
        {
         for(int j=1; j*j<=i; j++)
          {
           int square = j*j;
      
           int notTake = dp[i];

           int take = 1e8;
           if(square<=i)
               take = 1 + dp[i-square];

           dp[i] = min(take,notTake);
          }
        }

       return dp[n];
    }
};