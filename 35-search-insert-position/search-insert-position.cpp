class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l=0, r=nums.size()-1;
        int mid = 0;
        while(l<=r)
         {
          mid = l+(r-l)/2;
          if(target==nums[mid])
           return mid;
          if(target>nums[mid])
            l = mid + 1;
          else
            r = mid - 1;
         }
        if(nums[mid]<target) 
         {
            return mid+1;
         }
        else 
        {
            //if(mid==0 || mid==nums.size()-1) return mid;
            return mid;
        }

    }
};