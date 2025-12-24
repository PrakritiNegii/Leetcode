class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> hashmap;
        int n = nums.size();
        for(int i=0; i<n; i++)
         {
          hashmap[nums[i]]++;
         }
        int max = INT_MIN;
        for(int val : nums)
         {
          if(hashmap[val]>hashmap[max]) max=val;
         }
        return max;
    }
};