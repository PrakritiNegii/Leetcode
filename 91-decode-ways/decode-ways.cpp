class Solution {
public:
    int totalDecodings(string &s, int i, vector<int>& dp)
     {
      if(s[i]=='0') return 0;

      if(i>=s.size()-1)
       {
         return 1;
       }

      if(dp[i]!=-1)
          return dp[i];
         
      int count = 0;

      count += totalDecodings(s,i+1,dp); //current single digit is valid go to next

      int l = s[i]-48, r = s[i+1]-48;
      int val = l*10 + r;

      if(val>=1 && val<=26) //current two digit no is valid go to next
        count+= totalDecodings(s,i+2,dp);
      
      return dp[i] = count;
     }

    int numDecodings(string s) {
      int n = s.size();
      vector<int> dp(n,-1);
      return totalDecodings(s,0,dp);
    }
};