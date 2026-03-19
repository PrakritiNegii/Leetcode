class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();

      vector<int> dp(n+1,0);
      dp[n] = 1; //if we reach the end then the string has a valid decoding

      for(int i=n-1; i>=0; i--)
       {
        if(s[i]=='0') continue;
        dp[i] += dp[i+1];
        if(i < n-1) //another character present after the current
          {
            int l = s[i]-48, r = s[i+1]-48;
            int val = l*10 + r;
            if(val<=26)
              dp[i] += dp[i+2];
          }
       }
      return dp[0];
    }
};