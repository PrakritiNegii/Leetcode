class Solution {
public:
    bool maxSplitSizeMid(vector<int>& nums, long long maxSum, int k)
     {
      int n = nums.size();
      long long sum = 0;
      int splits = 0;
      int i = 0;

      while(i<n)
       {
        sum += nums[i];
        if(sum>maxSum)
         {
          splits++;
          sum = nums[i];
         }
        i++;
       }

      splits++; //including the last split
      if(splits<=k) return true; //a probable answer but check for smaller possible maxSum
      return false; //increase size of maxSum too many splits
     }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(),nums.end());
        long long right = accumulate(nums.begin(),nums.end(),0);

        while(left<=right)
         {
          long long mid = (right-left)/2 + left;

          bool isPossible = maxSplitSizeMid(nums,mid,k);

          if(isPossible)
            right = mid - 1;
          else
            left = mid + 1;
         }

        return left;
    }
};