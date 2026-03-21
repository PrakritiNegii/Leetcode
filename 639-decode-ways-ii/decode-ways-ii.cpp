#define MOD 1000000007

class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();
      vector<long long> dp(n+1,0);
      dp[n] = 1LL;

      for(int i=n-1; i>=0; i--)
       {
        if(s[i]=='0') 
         {
          continue;
         }
        if(s[i]=='*')
         {
          dp[i] = (9LL * dp[i+1]) % MOD;
          if(i<n-1)
           {
            if(s[i+1]=='*') dp[i] = (dp[i] + (15LL * dp[i+2]) % MOD) % MOD;
            else if(s[i+1]<='6') dp[i] = (dp[i] + (2LL * dp[i+2]) % MOD) % MOD;
                 else dp[i] = (dp[i] + dp[i+2]) % MOD;
           }
         }
        else
         {
          dp[i] = dp[i+1];
          if(i<n-1 && s[i]<='2')
           {
            if(s[i+1]=='*')
             {
              if(s[i]=='1') dp[i] = (dp[i] + (dp[i+2] * 9LL) % MOD) % MOD;
              else dp[i] = (dp[i] + (dp[i+2] * 6LL) % MOD) % MOD;
             }
            else
             {
              if(s[i]=='1') dp[i] = (dp[i] + dp[i+2]) % MOD;
              if(s[i]=='2' && s[i+1]<='6') dp[i] = (dp[i] + dp[i+2]) % MOD;
             }
           }
         }
       }  

      return dp[0];
    }
};