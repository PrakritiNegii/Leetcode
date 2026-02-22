class Solution {
public:
    string maximumXor(string s, string t) {
     int n = s.size();
     string ans = "";

     int t_ones=0;
        
     for(int i=0; i<n; i++)
         {
          if(t[i]=='1')
           t_ones++;
         }
    //changing s_zeroes to ones using t_ones
     int i=0;
     while(i<n)
         {
          if(s[i]=='0' && t_ones>0)
          {
            ans+='1';
            t_ones--;
          }
          else
              ans+=s[i];
          i++;
         }
      //changing minimum ones in ans to zero if t_ones are left
      i=n-1;
      while(i>=0 && t_ones>0)
          {
            if(s[i]=='1')
            {
             ans[i] = '0';
             t_ones--;
            }
            i--;
          }

      return ans;
    }
};