class Solution {
public:
    bool isPalindrome(string s) {
       int size = s.size();
       string ss = "";
       int i=0;
       while(i<size)
        {
         if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))
           ss += s[i];
         else if(s[i]>=65 && s[i]<=90)
           ss += tolower(s[i]);//ss = ss + (char)(s[i] + 32); //ss += tolower(s[i]);
         i++;
        }
       return isPalin(ss,0,ss.size()-1); 
    }
    bool isPalin(string& s, int i, int j)
     {
      if(i>=j) return true;
      if(s[i]!=s[j]) return false;
      return isPalin(s,i+1,j-1);
     }
};