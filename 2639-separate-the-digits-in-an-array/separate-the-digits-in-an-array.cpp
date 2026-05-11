class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++)
         {
          int size = 0;
          int num = nums[i]; 
          while(num>0)
           {
            size++;
            num = num / 10;
           }

          num = nums[i];
          while(size>0)
           {
            int divisor = pow(10,size-1);
            ans.push_back(num/divisor);
            num = num - (num/divisor)*divisor;

            size--;
           }
         }

        return ans;
    }
};