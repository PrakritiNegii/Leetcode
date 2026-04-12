class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        int maxDistIdx = 0;
        int steps = 0;

        for(int i=0; i<n-1; i++)
         {
          maxDistIdx = max(maxDistIdx,i+nums[i]);
          if(rightmost==i)
           {
            rightmost = maxDistIdx;
            steps++;
           }
          if(rightmost>=n-1) break;
         }
        return steps;
    }
};