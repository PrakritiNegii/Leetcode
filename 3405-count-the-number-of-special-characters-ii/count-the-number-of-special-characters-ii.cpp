class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> lowerCase(26,0);
        vector<int> upperCase(26,0);

        for(int i=0; i<n; i++)
         {
          int ch = word[i];
          int idx = -1;

          if(ch>=97) //lowercase
           {
            idx = ch - 'a';
            if(upperCase[idx]==1) lowerCase[idx] = -1;
            else lowerCase[idx] = 1;
           }
          else
           {
            idx = ch - 'A';
            upperCase[idx] = 1;
           }         
         }

        int special = 0;
        for(int i=0; i<26; i++)
          if(lowerCase[i]==1 && upperCase[i]==1) 
            special++;

        return special;
    }
};