class Solution {
public:     
    int longestCommonSubsequence(string s1, string s2) {
       int n1=s1.size(), n2=s2.size();
       vector<int> prev(n2+1,0), curr(n2+1,0);

       for(int i=1; i<=n1; i++)
        {
         for(int j=1; j<=n2; j++)
          {
           if(s1[i-1]==s2[j-1]) 
              curr[j] = 1 + prev[j-1];
           else
            {
              curr[j] = max(prev[j],curr[j-1]);
            }
          }
         prev = curr;
        }     

       return prev[n2]; 
    }
};