class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        int n = s.size();
        int fl=0, fr=0;
        int len = 1;
        //for odd length string
        for(int i=0; i<n; i++)
         {
          int l=i, r=i;
          bool palin = true;
          while(l>=0 && r<n)
           {
            if(s[l]!=s[r])
             {
              if(r-l-1 > len) 
               {
                len = r-l-1;
                fl = l+1;
                fr = r-1;
               }
              palin = false;
              break;
             }
            l--; r++;
           }
          if(palin && len < r-l-1)
           {
            len = r-l-1; fl=l+1; fr=r-1;
           } 
         }

        //for even length string
        for(int i=0; i<n-1; i++)
         {
          int l=i, r=i+1;
          if(s[l]!=s[r]) continue;
          bool palin = true;
          while(l>=0 && r<n)
           {
            if(s[l]!=s[r])
             {
              if(r-l-1 > len) 
               {
                len = r-l-1;
                fl = l+1;
                fr = r-1;
               }
              palin = false;
              break;
             }
            l--; r++;
           }
          if(palin && len < r-l-1)
           {
            len = r-l-1; fl=l+1; fr=r-1;
           } 
         }

        string ss = s.substr(fl,len);  //(start,length);
        return ss;
    }
};