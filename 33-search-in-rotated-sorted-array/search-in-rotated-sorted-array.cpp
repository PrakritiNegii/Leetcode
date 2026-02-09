class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left<=right)
         {
          int mid = (right-left)/2 + left;
          if(nums[mid]==target) return mid;
          if(nums[mid]>=nums[left]) // sorted left half
           {
            if(target<nums[mid] && target>=nums[left])
             {
              right = mid-1;
             }
            else
             {
              left = mid + 1;
             }
           }
          else //sorted right half
            {
             if(target>nums[mid] && target<=nums[right])
              {
               left = mid+1;
              }
             else
              {
               right = mid - 1;
              }
            }
         }

        return -1;
    }
};