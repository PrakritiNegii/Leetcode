class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i=0; i<n; i++)
         {
          total += nums[i];
         }
        
        if(total%2==1) return false;
        
        total/=2;

        vector<bool> prev(total+1,false);
        prev[0] = true;
        if(nums[0] <= total)
          prev[nums[0]] = true;

        for(int i=1; i<n; i++)
         {
          vector<bool> curr(total+1,false);
          curr[0] = true;

          for(int j=1; j<=total; j++)
           {
            bool s1 = false;

            //picking for subset 1;
            if(nums[i]<=j)
              s1 = prev[j-nums[i]];

            //picking for subset 2 or not picking for subset 1;
            bool s2 = prev[j];

            curr[j] = s1 || s2;
           }
          prev = curr;
         }

        return prev[total];
    }
};