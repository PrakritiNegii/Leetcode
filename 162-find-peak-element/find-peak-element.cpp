class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int left = 0, right = n;

        while(left<=right)
         {
          int mid = (right-left)/2 + left;
          if(mid==0)
           {
            if(nums[mid]>nums[mid+1]) return mid;
            else left = mid+1;
           }
          else if(mid==n-1)
                {
                 if(nums[mid]>nums[mid-1]) return mid;
                 return right=mid-1;
                }
               else
                {
                 if(nums[mid]<nums[mid-1]) right = mid-1;
                 else if(nums[mid]<nums[mid+1]) left = mid+1;
                      else return mid;
                } 
         }
        return -1;
    }
};