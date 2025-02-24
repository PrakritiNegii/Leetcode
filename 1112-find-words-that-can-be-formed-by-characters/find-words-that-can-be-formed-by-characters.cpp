class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
     int count = 0;
     int c[26] = {};
     for(int i=0; i<chars.size(); i++)
      {
       c[chars[i]-97]++;
      }
     for(string w : words)
      {
       int cmp[26] = {};
       int f = 0;
       for(int i=0; i<w.size(); i++)
        {
         int x = w[i]-97;
         cmp[x]++;
         if(cmp[x]>c[x]) 
          {
           f = 1;
           break;
          }
        }
       if(f==0) 
         count = count + w.size();
      }
     return count;
    }
};