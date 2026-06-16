class Solution {
public:
    string processStr(string s) {
       int n = s.size();

       string ans = "";
       int i=0, j=0; //i is index for s and j is index for ans

       while(i<n)
        {
         if(s[i]=='*')
          {
           if(j>0) j--;
          }
         else if(s[i]=='#')
               {
                if(j==ans.size())
                 {
                  cout<<"\t\tdoubled equal"<<endl;
                  ans += ans;
                  j = ans.size();
                 }
                else 
                 {
                  int x = 0;
                  int y = j;
                  while(y<ans.size() && x<j)
                   {
                    ans[y] = ans[x];
                    y++; x++;
                   }
                  string ss = ans.substr(x,j);
                  ans += ss;

                  j += j;
                 }
               }
              else if(s[i]=='%')
                    {
                     reverse(ans.begin(),ans.begin()+j);
                    }
                   else
                     {
                      if(ans.size()==j)
                         ans += s[i];
                      else 
                         ans[j] = s[i];
                      j++;
                     }
            i++;
        }

      string res = "";
      for(int y=0; y<j; y++)
        res += ans[y];

      return res;
    }
};