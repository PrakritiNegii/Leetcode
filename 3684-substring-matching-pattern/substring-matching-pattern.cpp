class Solution {
public:
    int hasSubstring(string s, int i, int n, string p, int j, int m)
     {
      while(i<=n)
       {
        int x = i;
        int y = j;
        while(y<=m)
         {
          if(s[x]!=p[y]) break;
          y++; x++;
         }
        if(y>m) return x;
        i++;
       }
      return -1;
     }

    bool hasMatch(string s, string p) {
      int n = s.size(), m = p.size();

      int star = -1;

      for(int j=0; j<m; j++)
        if(p[j]=='*')
         {
          star = j;
          break;
         }

// cout<<"star\t"<<star<<endl;
      int idx = 0;
      if(star!=0)
        idx = hasSubstring(s,0,n-1,p,0,star-1);

    // cout<<"1-idx\t"<<idx<<endl;

      if(idx==-1) return false;

      if(star!=m-1)
        idx = hasSubstring(s,idx,n-1,p,star+1,m-1);

            // cout<<"2-idx\t"<<idx<<endl;


      if(idx==-1) return false;
      
      return true;
    }
};