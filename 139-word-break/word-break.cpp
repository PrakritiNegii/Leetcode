class Solution {
public:
    bool breakable(string &s, unordered_set<string>& st, int i, vector<int>& dp)
     {
      if(i>=s.size()) return true;
      if(dp[i]!=-1) return dp[i];
      
      string segment = "";
      bool canBreak = false;
      for(int j=i; j<s.size(); j++)
       {
        segment += s[j];
        if(st.count(segment)!=0)
           canBreak = breakable(s,st,j+1,dp);

        if(canBreak) return dp[j+1] = true;
       }
      return dp[i] = false;
     }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set <string> st;
        vector<int> dp(n+1,-1);

        for(string str : wordDict)
           st.insert(str);

        return breakable(s,st,0,dp);
    }
};