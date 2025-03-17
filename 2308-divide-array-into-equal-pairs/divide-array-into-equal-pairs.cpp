class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2!=0)
          return false;
        int freq[500] = {0};
        for(int i=0; i<nums.size(); i++)
         {
          freq[nums[i]-1]++;
         }
        for(int i=0; i<nums.size(); i++)
         {
          if(freq[nums[i]-1]%2!=0)
            return false;
         }
        return true;
    }
};