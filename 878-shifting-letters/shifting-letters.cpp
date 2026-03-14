class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
      int n = s.size();

      int toShift = 0;
      for(int i=0; i<n; i++)
       {
        shifts[i] = shifts[i]%26;
        toShift += shifts[i];
       }  
   
      for(int i=0; i<n; i++)
       {
        int shift = toShift % 26;
        int ch = ((s[i]-97) + shift) % 26;
        s[i] = (char) ch+97;

        toShift -= shifts[i];
       }
      return s;
    }
};