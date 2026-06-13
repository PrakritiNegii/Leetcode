class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();

        vector<unsigned long long> prev(m+1,0), curr(m+1,0); //shorter string for row

        prev[0] = 1; curr[0] = 1;
        for(int i=1; i<=n; i++)
         {
            for(int j=1; j<=m; j++)
              {
                unsigned long long take = 0;
                if(s[i-1]==t[j-1]) 
                   take = prev[j-1];
                
                unsigned long long notTake = prev[j];

                curr[j] = take + notTake;
              }
            prev = curr;
         }

        return (int) prev[m];
    }
};