class Solution {
public:
    bool isMatch(string s, string p) {
     int n = s.size(), m = p.size();

     vector<int> next(m+1,false), curr(m+1,false);

     next[m] = true;

     curr[m] = false;

     for(int j=m-1; j>=0; j--)
      {
       if(p[j]!='*') break;
       next[j] = true;
      }

     for(int i=n-1; i>=0; i--)
      {
       for(int j=m-1; j>=0; j--)
        {
         if(s[i]==p[j] || p[j]=='?') 
          {
           curr[j] = next[j+1];
          }
         else if(p[j]=='*') 
               {
                bool notTake = curr[j+1]; //not taking any character to match(matching empty space)
                bool take = next[j]; //taking the character

                curr[j] = take | notTake;
               }
              else
                curr[j] = false;
        }
       next = curr;
      }

     return next[0];   
    }
};