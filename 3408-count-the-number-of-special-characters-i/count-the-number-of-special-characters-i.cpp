class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        if(n==1) return false;

        vector<bool> lowerCase(26,false);
        vector<bool> upperCase(26,false);

        int count = 0;
        for(int i=0; i<n; i++)
         {
          int ch = word[i];
          if(ch>=97) //lower case letters
           {
            ch -= 'a';
            if(lowerCase[ch]==true) continue;
            lowerCase[ch] = true;
            if(upperCase[ch]==true) count++;
           }
          else
           {
            ch -= 'A';
            if(upperCase[ch]==true) continue;
            upperCase[ch] = true;
            if(lowerCase[ch]==true) count++;
           }
         }

        return count;
    }
};