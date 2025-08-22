class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<int> dp(s.size(),-1);
       return find(s,wordDict,0,dp);
    }

    bool find(string s, vector<string>& wordDict, int pos, vector<int>&dp)
     {
      if(pos>=s.size())
        return true;
      if(dp[pos]!=-1) 
        return dp[pos];

      for(int k=0; k<wordDict.size(); k++)
       {
        if(s[pos]==wordDict[k][0])
         {
          int p = pos+1;
          int c = 1;
          bool flag = true;
          while(c<wordDict[k].size())
           {
            if(p>=s.size() || s[p]!=wordDict[k][c])
              {
                flag = false;
                break;
              }
            p++;
            c++;
           }
          if(flag==true)
           {
            bool res = find(s,wordDict,p,dp);
            if(res==true) 
              {
                dp[pos] = 1;
                return res;
              }
            else
              {
                dp[pos] = 0;
              }
           }
         }
       }
     return false;
     }
};