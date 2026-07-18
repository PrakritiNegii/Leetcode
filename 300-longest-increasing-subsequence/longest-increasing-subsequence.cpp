class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> current(n+1,0), previous(n+1,0);

        for(int prev=0; prev<=n; prev++)
         {
          if(prev==n || nums[0]<nums[prev])
            current[prev] = 1;
          else
            current[prev] = 0;
         }
        previous = current;

        for(int i=1; i<n; i++)
         {
          for(int prev=0; prev<=n; prev++)
           {
            int notTake = previous[prev];
            int take = 0;
            if(prev==n || nums[i]<nums[prev])
                take = 1 + previous[i];

            current[prev] = max(notTake,take);
           }
          previous = current;
         }
        return previous[n];
    }
};