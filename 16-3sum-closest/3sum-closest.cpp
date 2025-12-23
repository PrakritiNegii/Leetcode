class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int FinalSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for(int i=0; i<n; i++)
         {
          if(i>0 && nums[i]==nums[i-1]) continue;
          int left = i+1;
          int right = n-1;

          while(left<right)
           {
            if(left>i+1 && nums[left]==nums[left-1])
             {
              left++;
              continue;
             }

            if(right<n-1 && nums[right]==nums[right+1])
             {
              right--;
              continue;
             }

            int sum = nums[i] + nums[left] + nums[right];
            int x = abs(FinalSum-target);
            int y = abs(sum-target);

            if(y<x) FinalSum = sum;
            if(sum>target) right--;
            else if(sum<target) left++;
                 else 
                  {
                    left++;
                    right--;
                    return FinalSum;
                  }
           }
         }
        return FinalSum;
    }
};