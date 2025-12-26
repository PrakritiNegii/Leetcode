class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> ans;
      int n = nums.size();
      int s = n/3;

      unordered_map <int,int> hashmap;
      for(int i=0; i<n; i++)
       {
        int val = nums[i];
        hashmap[val]++;
       }
      
      for(auto el: hashmap)
       {
        if(el.second>s) ans.push_back(el.first);
       }

      return ans;
    }
};