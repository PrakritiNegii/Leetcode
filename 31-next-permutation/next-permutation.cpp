class Solution {
public:
    void reverse(vector<int>&nums, int i)
     {
      int j = nums.size()-1;
      while(i>=0 && i<j)
       {
        swap(nums[i],nums[j]);
        i++; j--;
       }
     }
    void nextPermutation(vector<int>& nums) {
        int revInd = 0;
        int n = nums.size();
        for(int i=1; i<n; i++)
         {
          if(nums[i]>nums[i-1]) revInd = i;
         }
        if(revInd==n-1) reverse(nums,n-2);
        else
         {
          reverse(nums,revInd);
          if(revInd>0)
           {
            int i=revInd;
            while(i<n)
             {
              if(nums[revInd-1]>=nums[i]) i++;
              else break;
             }
            swap(nums[revInd-1],nums[i]);
           }
         } 
    }
};