class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();

        int minimum = nums[0];
        int maximum = nums[0];
        int minCount = 1;
        int maxCount = 1;

        for(int i=1; i<n; i++)
         {
          if(minimum>nums[i])
           {
            minimum = nums[i];
            minCount = 1;
           }
          else if(minimum==nums[i])
                 minCount++;

          if(maximum<nums[i])
           {
            maximum = nums[i];
            maxCount = 1;
           }
          else if(maximum==nums[i])
                 maxCount++;
         }

        int ans = n-minCount-maxCount;

        if(ans<0) return 0;
        return ans;
    }
};