class Solution {
public:
    bool canBeEqual(string s1, string s2) {
      if(s1==s2) return true;

      int i=0, j=2;
      string ss1 = s1;
      char temp = ss1[i];
      ss1[i] = ss1[j];
      ss1[j] = temp;
      if(ss1 == s2) return true;

      i=1; j=3;
      temp = ss1[i];
      ss1[i] = ss1[j];
      ss1[j] = temp;
      if(ss1 == s2) return true;

      ss1 = s1;
      temp = ss1[i];
      ss1[i] = ss1[j];
      ss1[j] = temp;
      if(ss1 == s2) return true;

      return false;
    }
};