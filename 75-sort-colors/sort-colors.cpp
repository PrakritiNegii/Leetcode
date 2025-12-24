class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //arranging zeroes to the start of the array

        int j=n-1; 
        while(j>=0 && nums[j]!=0)
         {
          j--; //find first 0 from the last
         }
        for(int i=j-1; i>=0 && j>=0; i--) //i points to non zero element to be swapped
         {
          if(nums[i]!=0)
           {
            swap(nums[i],nums[j]);
            j--;
           }
         }

        j = 0; 
        while(j<n && nums[j]!=2)
         {
          j++; //find first 2 from the start
         }
        for(int i=j+1; i<n; i++) //i points to non 2 element to be swapped
         {
          if(nums[i]!=2)
           {
            swap(nums[i],nums[j]);
            j++;
           }
         }
    }
};