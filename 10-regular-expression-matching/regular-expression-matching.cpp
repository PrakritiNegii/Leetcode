class Solution {
public:
    bool isMatch(string s, string p) {
       int n = s.size(), m = p.size();

       vector<bool> prev(m+1,0), curr(m+1,0);

       prev[0] = true;  //prev here is i=0;

       curr[0] = true; //curr here is also i = 0;

       for(int i=0; i<=n; i++)
        {
         if(i>0) curr[0] = false;
         for(int j=1; j<=m; j++)
          {
           if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.')) 
              curr[j] = prev[j-1];
           else if(p[j-1]=='*')
                 {
                   int notTake = curr[j-2]; //matching value before * with nothing
                   int take = false;
                   if(i>0 && (p[j-2]=='.' || p[j-2]==s[i-1])) 
                       take = prev[j]/*one match*/;
                   curr[j] = notTake | take;
                 }
                else 
                   curr[j] = false;
          }
         prev = curr;
        }

       return prev[m];
    }
};