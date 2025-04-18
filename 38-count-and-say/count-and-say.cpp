class Solution {
public:
    string countAndSay(int n) {
       if(n==1) return "1";
       string str = countAndSay(n-1); 
       int size = str.size();
       string res = "";
       char prev=str[0];
       int i=0;
       int c=0;
       while(i<size)
        {
         if(str[i]==prev) c++;
         else
          {
           res = res + to_string(c) + prev;
           c=1;
          }
         prev = str[i];
         i++;
        }
       res = res + to_string(c) + prev;
       return res;
    }
};