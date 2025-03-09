class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int l = 0;
        bool flag = false;
        while(i>=0)
         {
          if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
           {
            l++;
            i--;
            flag = true;
           }
          else 
           {
            if(flag==false) i--;
            else break;
           }
         }
        return l;
    }
};