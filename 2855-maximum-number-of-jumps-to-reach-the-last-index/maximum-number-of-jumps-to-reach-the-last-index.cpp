class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
      int n = nums.size();

      vector<int> dp(n,0);

      for(int j=1; j<n; j++)
       {
         int jumps = -1;
         for(int i=j-1; i>=0; i--)
          {
            int diff = nums[j] - nums[i];
            if(diff>=-target && diff<=target)
              {
                int jmp = dp[i];
                if(jmp!=-1)
                jumps = max(jumps,1+jmp);
              }
          }
         dp[j] = jumps;
       }
      
      return dp[n-1];
    }
};