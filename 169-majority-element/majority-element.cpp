class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> hashmap;
        int n = nums.size();
        for(int i=0; i<n; i++)
         {
          hashmap[nums[i]]++;
         }
        int max = INT_MIN, maxNo;
        for(auto val : hashmap)
         {
          if(val.second > max) 
           {
            max = val.second;
            maxNo = val.first;
           }
         }
        return maxNo;
    }
};