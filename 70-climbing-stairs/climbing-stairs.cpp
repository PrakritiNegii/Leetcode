class Solution {
public:
      int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        return calculate(n,dp);
    }
      int calculate(int n, vector<int>&dp)
     {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]==-1)
          return dp[n] = calculate(n-1,dp) + calculate(n-2,dp);   
        return dp[n];
     }
};
