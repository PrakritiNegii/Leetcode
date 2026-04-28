class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set <string> st{begin(wordDict), end(wordDict)};
        vector<bool> dp(n+1,false);
        dp[n] = true;

        for(int i=n-1; i>=0; i--)
         {
           string segment = "";
           for(int j=i; j<s.size(); j++)
            {
             segment += s[j];
             if(st.count(segment)!=0)
               dp[i] = dp[j+1];
             if(dp[i]) break;
            }
         }

        return dp[0];
    }
};