class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
     {
      sort(nums.begin(),nums.end());
      int size = nums.size();
      int maxc = 1;
      int i=0, j=0;
      long long sum = nums[0];
      while(j<size)
       {
        long long comp = (j-i+1)* (long long) nums[j];
        if(comp <= sum+k)
         {
          maxc = max(maxc,(j-i+1));
          j++;
          if(j<size) sum+=nums[j];
         }
        else
         {
          sum-=nums[i];
          i++;
         }
       }
      return maxc;
     }
};