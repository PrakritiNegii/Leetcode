class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> nums;
        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            nums.push_back(grid[i][j]);
           }
         }

        sort(nums.begin(),nums.end());

        /*
        you do not need to average two medians for even length.
        For minimizing absolute distance, any value between the two middle values works.
        */
        int median = nums[nums.size()/2];

        long long operations = 0;
        for(int i=0; i<nums.size(); i++)
         {
          int diff = abs(median - nums[i]);
          if(diff % x != 0) return -1;
          operations += diff/x;
         }
        
        return operations;
    }
};