class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
      for(int i=0; i<n-3; i++)
       {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n-2; j++)
         {
          if(j>i+1 && nums[j]==nums[j-1]) continue;

          int left = j+1, right = n-1;
          while(left<right)
           {
            if(left>j+1 && nums[left]==nums[left-1])
             {
              left++;
              continue;
             }
            if(right<n-1 && nums[right]==nums[right+1])
             {
              right--;
              continue;
             }
            long long sum2 = nums[left] + nums[right];
            long long sum4 = nums[i] + nums[j] + sum2;
            if(sum4==target)
             {
              res.push_back({nums[i],nums[j],nums[left],nums[right]});
              left++; right--;
             }
            else if(sum4<target) //a larger sum is require hence, move towards right
                  {
                    left++;
                  }
                 else
                   {
                    right--;
                   }
           }
         }
       }
        return res; 
    }
};