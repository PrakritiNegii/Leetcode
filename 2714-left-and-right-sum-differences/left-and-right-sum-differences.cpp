class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,0);
        int total = 0;

        for(int i=0; i<n; i++)
         {
          total += nums[i];
         }

        answer[0] = total-nums[0];
        int left=0, right=0;
        for(int i=1; i<n; i++)
         {
          left += nums[i-1];
          right = total-left-nums[i];
          answer[i] = abs(left-right);
         }

        return answer;
    }
};