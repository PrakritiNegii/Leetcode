class Solution {
public:
    int maxJumps(vector<int> &nums, int j, int target, vector<int> &dp)
     {
      if(j==0) return 0;
      if(dp[j]!=0) return dp[j];

      int jumps = -1;
      for(int i=j-1; i>=0; i--)
       {
        int diff = nums[j] - nums[i];
        if(diff>=-target && diff<=target)
          {
           int jmp = maxJumps(nums,i,target,dp);
           if(jmp!=-1)
             jumps = max(jumps,1+jmp);
          }
       }

      return dp[j] = jumps;
     }
    int maximumJumps(vector<int>& nums, int target) {
      int n = nums.size();

      vector<int> dp(n,0);
      
      return maxJumps(nums,n-1,target,dp);
    }
};