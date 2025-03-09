class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
     {
      int size = colors.size();
      int i=1, j=0, a = 0, start = 0;
      int alt=0, c=0, l=0;
      for(;;)
       { 
        if(i==k-1)
          l++;
        if(l>1)
          break; 
        a = colors[j] ^ colors[i];
        if(a==0)
         {
          start = i;
          alt = 0;
         }
        else 
        {
          alt++;
          if(alt==k)
         {
           start = start + 1;
           alt--;
         }
        }
        if(alt == k-1)
          c++;

        j = i;
        i = (i+1)%size;
       }
      return c;   
     } 
};