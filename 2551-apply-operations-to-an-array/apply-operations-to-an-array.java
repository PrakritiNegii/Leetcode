class Solution {
    public int[] applyOperations(int[] nums) {
        int i, j=0;
        for(i=0; i<nums.length-1; i++)
         {
          if(nums[i]==nums[i+1])
           {
            nums[i]*=2;
            nums[i+1]=0;
           }
          if(nums[i]!=0)
           {
            nums[j] = nums[i];
            j++;
           }
         }
        nums[j] = nums[i];
        j++;  
        while(j<nums.length)
         {
          nums[j] = 0;
          j++;
         }
         return nums;
    }
}