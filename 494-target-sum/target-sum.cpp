class Solution {
public:
    int totalWays(vector<int>& nums, int i, int target, map<pair<int,int>,int>& dp)
     {
      if(i==0)
       {
        int t1 = target + nums[0];
        int t2 = target - nums[0];

        int count = 0;
        if(t1==0) count++;
        if(t2==0) count++;

        return count;
       }
    
      if(dp.count({i,target})!=0) return dp[{i,target}];

      //+
      int t1 = totalWays(nums,i-1,target-nums[i],dp);

      //-
      int t2 = totalWays(nums,i-1,target+nums[i],dp);

      return dp[{i,target}] = t1+t2;
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        map<pair<int,int>,int> dp;
        return totalWays(nums,n-1,target,dp);
    }
};