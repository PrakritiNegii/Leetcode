#define MOD 1000000007

class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();

      long long next1 = 1LL, next2 = 1LL;

      for(int i=n-1; i>=0; i--)
       {
        int curr = 0;
        if(s[i]=='0')
          {
            next2 = next1;
            next1 = curr;
            continue;
          }
        if(s[i]=='*')
         {
          curr = (9LL * next1) % MOD;
          if(i<n-1)
           {
            if(s[i+1]=='*') curr = (curr + (15LL * next2) % MOD) % MOD;
            else if(s[i+1]<='6') curr = (curr + (2LL * next2) % MOD) % MOD;
                 else curr = (curr + next2) % MOD;
           }
         }
        else
         {
          curr = next1;
          if(i<n-1 && s[i]<='2')
           {
            if(s[i+1]=='*')
             {
              if(s[i]=='1') curr = (curr + (next2 * 9LL) % MOD) % MOD;
              else curr = (curr + (next2 * 6LL) % MOD) % MOD;
             }
            else
             {
              if(s[i]=='1') curr = (curr + next2) % MOD;
              if(s[i]=='2' && s[i+1]<='6') curr = (curr + next2) % MOD;
             }
           }
         }
        next2 = next1;
        next1 = curr;
       }  

      return next1;
    }
};