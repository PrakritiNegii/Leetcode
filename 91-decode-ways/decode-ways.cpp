class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();

      //only the valid decoding possibility of the next 2 strings required
      int next1 = 1, next2 = 1;

      for(int i=n-1; i>=0; i--)
       {
        int curr = 0;
        if(s[i]!='0') 
         {
           curr += next1;
           if(i < n-1) //another character present after the current
            {
              if(s[i]<='1' || (s[i]=='2' && s[i+1]<='6') )
                curr += next2;
            }
         }
         next2 = next1;
         next1 = curr;
       }
      return next1;
    }
};