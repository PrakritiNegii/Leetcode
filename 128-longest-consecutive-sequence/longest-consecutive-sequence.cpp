class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set <int> us;
        for(int i=0; i<n; i++) 
         {
          us.insert(nums[i]);
         }
        int maxLen = 1;
        for(auto it : us)
         {
          if(us.find(it-1)==us.end())
           {
            int cnt = 1;
            int x = it;
            while(us.find(x+1)!=us.end())
             {
              x = x + 1;
              cnt = cnt + 1;
             }
            maxLen = max(maxLen,cnt);
           }
         }
        return maxLen;
    }
};