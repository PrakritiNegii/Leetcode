class Solution {
public:
    int numSteps(string s) {
        int n = s.size()-1;

        int c=0;
        while(n>=0)
         {
          if(s[n]=='1')
           {
            if(n==0) return c;
            int j = n;
            while(j>=0 && s[j]=='1')
             {
              s[j] = '0';
              j--;
             }
            if(j>=0) s[j] = '1';
           }
          else
           {
            n--;
           }
           c++;
         }

        return c;
    }
};