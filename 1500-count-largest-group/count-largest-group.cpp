class Solution {
public:
    int countLargestGroup(int n) {
       unordered_map <int,int> hash;
       for(int i=1; i<=n; i++)
        {
         int d = i;
         int sum = 0;
         while(d>0)
          {
           sum = sum + d%10;
           d/=10;
          }
         hash[sum]++;
        }
      int count = 0;
      int maximum = 0;
      for(auto &p : hash)
       {
        if(p.second>maximum) 
         {
          maximum = p.second;
          count = 0;
         }
        if(p.second==maximum)
          count++;
       } 
      return count;
    }
};