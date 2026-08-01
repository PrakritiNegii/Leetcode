class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> count(n,1);
        int maxLis = 1;

        for(int i=1; i<n; i++)
         {
          for(int j=0; j<i; j++)
           {
            if(nums[i]>nums[j])
             {
              if(lis[i]==lis[j]+1) count[i] += count[j];
              else if(lis[i]<lis[j]+1)
                    {
                     lis[i] = lis[j] + 1;
                     count[i] = count[j];
                    }
             }
           }
          maxLis = max(maxLis,lis[i]);
         }

        int c = 0;
        for(int i=0; i<n; i++)
         {
          if(lis[i]==maxLis) c += count[i];
         }

        return c;
    }
};