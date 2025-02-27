class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //int arr[nums] = {0};
        int size = nums.size();
        int i;
        for(i=0; i<size; i++)
         {
          int c = 1;
          for(int j=i+1; j<size; j++)
           {
            if(nums[i]==nums[j])
              c++;
           }
          if(c>size/2)
           break;
         }
       return nums[i];
    }
};