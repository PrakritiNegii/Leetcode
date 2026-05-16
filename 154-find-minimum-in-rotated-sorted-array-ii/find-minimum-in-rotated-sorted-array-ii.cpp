class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n-1;

        while(left<right)
         {
          int mid = (right-left)/2 + left;

          if(nums[mid]>nums[right]) //left half is sorted
           {
            left = mid + 1;
           }
          else if(nums[mid]<nums[right]) //right half is sorted
                {
                 right = mid;
                }
               else
                  {
                    right--;
                  }
         }

        return nums[left]; //or nums[right] if left==right
    }
};