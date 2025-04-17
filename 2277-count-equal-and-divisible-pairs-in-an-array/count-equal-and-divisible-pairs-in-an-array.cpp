class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int c=0;
        for(int i=0; i<nums.size(); i++)
         {
          for(int j=nums.size()-1; j>i; j--)
           {
            int product = i*j;
            if(product%k==0)
             {
              if(nums[i]==nums[j]) 
                c++;
             }
           }
         }
        return c;
    }
};