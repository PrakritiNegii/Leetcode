class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0, zero2 = 0, ones = 0, maxOnes = 0;
        int i = 0, start = 0;
        
        while(i<nums.size())
         {
          if(nums[i]==1) i++;
          else
           {
            if(zero<k) 
             {
              zero++; 
              i++;
             }
            else
             {
              ones = i - start;
              maxOnes = max(ones,maxOnes);
              if(nums[start]==0) start++;
              else 
               {
                while(nums[start]!=0)
                 {
                  start++;
                 }
                start++;
               }
              i++;
             }
           }
         }
        ones = i - start;
        maxOnes = max(ones,maxOnes);
        return maxOnes; 
    }
};