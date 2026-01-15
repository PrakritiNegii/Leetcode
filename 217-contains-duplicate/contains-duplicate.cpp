class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++)
         {
          int curr = nums[i];
          if(st.find(curr)!=st.end())
            return true;
          st.insert(curr);
         }

        return false;
    }
};