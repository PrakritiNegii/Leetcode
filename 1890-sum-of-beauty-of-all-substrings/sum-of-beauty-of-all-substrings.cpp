class Solution {
public:
    int beautySum(string s) {
        vector<int> alphabet(26,0);
        int n = s.size();

        int sum=0;

        for(int i=0; i<n; i++)
         {
          int ch = s[i]-97;
          alphabet[ch]++;

          for(int j=i+1; j<n; j++)
           {
            ch = s[j]-97;
            alphabet[ch]++;
            
            int least = 500, most = 0;

            for(int k=0; k<26; k++)
             {
              if(least>alphabet[k] && alphabet[k]>0) least = alphabet[k];
              if(most<alphabet[k]) most = alphabet[k];
             }

            sum += (most-least);
           }
          
          fill(alphabet.begin(),alphabet.end(),0);
         }
  
        return sum;
    }
};