//Using Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp; 
        dp.push_back(nums[0]);

        for(int i=1; i<n; i++)
         {
          if(dp.back()<nums[i]) 
            dp.push_back(nums[i]);
          else
           {
            int ind = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin(); //returns an iterator

            dp[ind] = nums[i];
           }
         }
        
        return dp.size();
    }
};