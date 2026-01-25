class Solution {
public:
    int partitionString(string s) {
       int alphabets[26] = {0};
       int size = s.size();
       
       int totalPartitions = 1;
       for(int i=0; i<size; i++)
        {
         int c = s[i]-97;
         if(alphabets[c])   
          { 
           totalPartitions++;
           for(int j=0; j<26; j++)
            alphabets[j] = 0;
          }
         alphabets[c]++;
        } 
       return totalPartitions;
    }
};