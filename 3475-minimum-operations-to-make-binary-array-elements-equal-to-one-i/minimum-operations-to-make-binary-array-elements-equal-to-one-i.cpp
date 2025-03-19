class Solution {
public:
    int minOperations(vector<int>& nums) 
     {
      int sum=0, start=0, c=0;
      for(int i=2; i<nums.size(); i++)
       {
        if(nums[start]==1)
         {
          start++;
          sum+=1;
         }
        else
         {
          int j=start;
          while(j!=i+1)
           {
            nums[j] = nums[j] ^ 1;
            j++;
           }
          sum+=1;
          c++;
          start++;
         }
       }   
      while(start!=nums.size())
       {
        sum = sum + nums[start++];
       }
      if(sum==nums.size()) return c;
      else return -1;
     }
};