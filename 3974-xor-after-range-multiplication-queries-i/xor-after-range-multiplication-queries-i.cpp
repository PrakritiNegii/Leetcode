class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        int n = nums.size();
        int q = queries.size();

        for(int i=0; i<q; i++)
         {
          int li = queries[i][0], ri = queries[i][1], ki = queries[i][2], vi = queries[i][3];
          int idx = li;
          while(idx<=ri)
           {
            long long val = nums[idx];
            val = (val * vi) % MOD;
            nums[idx] = (int) val;
            idx += ki;
           }
         }

        int totalXor = 0;
        for(int i=0; i<n; i++)
         {
          totalXor ^= nums[i];
         }

        return totalXor;
    }
};