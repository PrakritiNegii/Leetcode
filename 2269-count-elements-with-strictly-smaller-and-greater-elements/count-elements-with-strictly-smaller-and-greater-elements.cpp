class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();

        int min = nums[0];
        int max = nums[0];

        for(int i=1; i<n; i++)
         {
          if(min>nums[i]) min = nums[i];
          if(max<nums[i]) max = nums[i];
         }

        int c=0;
        for(int i=0; i<n; i++)
         {
          if(nums[i]>min && nums[i]<max) c++;
         }

        return c;
    }
};