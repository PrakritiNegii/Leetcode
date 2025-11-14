class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //j points to 0, i points to non-zero
        for(int j=0, i=1; i<nums.size();i++)
         {
          if(nums[j]!=0)
            {
              j++;
            }
          else
            {
              if(nums[i]!=0)
                {
                  swap(nums[j],nums[i]);
                  j++;
                }
            }
         }
     }
};