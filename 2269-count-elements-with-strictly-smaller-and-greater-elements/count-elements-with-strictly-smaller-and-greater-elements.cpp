class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();

        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());

        int c=0;
        for(int i=0; i<n; i++)
         {
          if(nums[i]>min && nums[i]<max) c++;
         }

        return c;
    }
};