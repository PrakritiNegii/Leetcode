class Solution {
public:
    int lowerRange(vector<int>& nums, int target)
     {
      int lower = -1;
      int left = 0;
      int right = nums.size()-1;

      while(left<=right)
       {
        int mid = (right-left)/2 + left;

        if(nums[mid]==target) 
         {
            lower = mid;
            right = mid-1;
         }
        else if(nums[mid]>target) 
               right = mid-1;
             else 
                 left = mid + 1;
       }

      return lower;
     }

    int higherRange(vector<int>& nums, int target)
     {
      int higher = -1;
      int left = 0;
      int right = nums.size()-1;

      while(left<=right)
       {
        int mid = (right-left)/2 + left;

        if(nums[mid]==target) 
         {
            higher = mid;
            left = mid+1;
         }
        else if(nums[mid]>target) 
               right = mid-1;
             else 
                 left = mid + 1;
       }

      return higher;
     }



    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerRange(nums,target);
        int higher = higherRange(nums,target);

        return {lower,higher};
    }
};