class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        unsigned long long sum = 0LL;
        unsigned long long product = 1LL;

        for(int i=0; i<n-1; i++) //first balance index assumed to be n-1
            sum += nums[i];

        for(int i=n-1; i>0; i--)
         {
          if(sum==product) return i;
          if(sum>product)
           {
            sum -= nums[i-1];
            product *= nums[i];
           }
          else return -1;
         }

        return -1;
    }
};