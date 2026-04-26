class Solution {
public:
    bool breakable(string &s, unordered_set<string>& st, int i, string segment, vector<int>& dp)
     {
      if(i==s.size()-1)
       {
        segment += s[i];
        if(st.count(segment)!=0) return true;
        return false;
       }
      
      segment += s[i];
      bool breaks1 = breakable(s,st,i+1,segment,dp);
      if(breaks1) return true;

      bool breaks2 = false;
      if(st.count(segment)!=0)
        {
         if(dp[i]!=-1) return dp[i];
         breaks2 = breakable(s,st,i+1,"",dp);
         dp[i] = breaks2;
        }
      
      return breaks2;
     }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set <string> st;
        vector<int> dp(n,-1);

        for(string str : wordDict)
           st.insert(str);

        return breakable(s,st,0,"",dp);
    }
};