class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());

        int maxLen = 1;
        int length = 1;
        for(int i=1; i<n; i++)
         {
          if(nums[i]==nums[i-1]) continue;
          if(nums[i]==(nums[i-1]+1)) length++;
          else
           {
            maxLen = max(maxLen,length);
            length = 1;
           }
         }
        maxLen = max(maxLen,length);

        return maxLen;
    }
};