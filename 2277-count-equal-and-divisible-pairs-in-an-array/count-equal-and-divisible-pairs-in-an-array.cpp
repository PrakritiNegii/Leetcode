class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int c=0, n=nums.size();
        for(int i=0; i<n; i++)
         {
          for(int j=n-1; j>i; j--)
           {
            if((i*j)%k==0 && (nums[i]==nums[j]))
                c++;
           }
         }
        return c;
    }
};