class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int FinalSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for(int i=0; i<n; i++)
         {
          int left = i+1;
          int right = n-1;

          while(left<right)
           {
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
                    break;
                  }
           }
          if(FinalSum==target) break;
         }
        return FinalSum;
    }
};