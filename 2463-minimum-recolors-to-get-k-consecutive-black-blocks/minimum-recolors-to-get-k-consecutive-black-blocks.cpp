class Solution {
public:
    int minimumRecolors(string blocks, int k) 
     {
      int minimum;
      int white = 0;
      for(int i=0; i<blocks.size(); i++)
       {
        if(blocks[i]=='W')
          white++;

        if(i==k-1)
          minimum = white;

        if(i>=k)
         {
          if(blocks[i-k]=='W')
            white--;
          minimum = min(minimum,white);
         }
       }
      return minimum;
     }
};