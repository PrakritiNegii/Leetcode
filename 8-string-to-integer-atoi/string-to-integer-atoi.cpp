class Solution {
public:
    int myAtoi(string s) {
      int n = 0;
      bool sign = true;
      bool num = false;

      int i=0;
      for(; i<s.size(); i++)  
       {
        if(s[i]=='-') sign = false; //sign is negative
        if(s[i]!=' ') break;
       }

      if(s[i]=='-' || s[i]=='+') 
        i++;

      for(;i<s.size(); i++)
       {
         if(s[i]>=48 && s[i]<=57)
          {
            // cout<<(int)s[i]<<"   i = "<<i<<endl;
            int digit = (int)s[i] - 48;
            long eh = (long) n*10 + digit;
            if(sign == true && eh>=INT_MAX)
             {
              n = INT_MAX;
              break;
             }
            else if(sign == false && eh>= (long)INT_MAX+1)
                  {
                   n = INT_MIN;
                   sign = true;
                   break;
                  }
                 else              
                   n = n*10 + ((int)s[i] - 48);
          }
         else break;
       }
      if(sign==false) n*=-1;
      return n;
    }
};