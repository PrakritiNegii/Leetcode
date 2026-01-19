class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int sSize = s.size();
        int j=0;
        int tSize = t.size();

        while(j<tSize)
         {
          if(s[i]==t[j]) i++;
          j++;
         }

        if(i==sSize) return true;
        return false;
    }
};