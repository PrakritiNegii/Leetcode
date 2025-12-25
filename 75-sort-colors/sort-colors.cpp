class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //arranging zeroes to the start of the array
        int low=0, mid=0, high=n-1;

        while(mid<=high)
         {
          if(nums[high]==2) 
           {
            high--;
           }
          else if(nums[high]==1)
                {
                 swap(nums[high],nums[mid]);
                 mid++;
                }
               else //nums[high]==0
                  {
                   swap(nums[high],nums[mid]);
                   swap(nums[mid],nums[low]);
                   mid++; low++;
                  } 
         }
  }
};