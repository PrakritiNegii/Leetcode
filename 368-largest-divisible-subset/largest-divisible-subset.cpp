class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
     {
      sort(nums.begin(),nums.end());
      int n = nums.size();
      vector<int> lis(n,1); //lis till given index
      vector<int> hash(n); //stores the previous index of lis

      int maxLis = 1;
      int maxIdx = 0;

      hash[0] = 0;
      for(int i=1; i<n; i++)
       {
        hash[i] = i;
        for(int j=0; j<i; j++)
         {
          if(nums[i]%nums[j]==0)
           {
            if(lis[j]+1 > lis[i])
             {
              lis[i] = lis[j]+1;
              hash[i] = j;
             }
           }
         }
        if(maxLis<lis[i])
         {
          maxLis = lis[i];
          maxIdx = i;
         }
       }

      vector<int> subset;
      int i = maxIdx;
      while(i!=hash[i])
       {
        subset.push_back(nums[i]);
        i = hash[i];
       }
      subset.push_back(nums[i]);

      return subset;
     }
};