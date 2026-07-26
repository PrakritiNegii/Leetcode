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
            int left=0, right=dp.size()-1;
            while(left<=right)
             {
              int mid = left + (right-left)/2;

              if(nums[i]<=dp[mid]) 
                right = mid - 1;
              else 
                left = mid + 1;
             }

            dp[left] = nums[i];
           }
         }
        
        return dp.size();
    }
};