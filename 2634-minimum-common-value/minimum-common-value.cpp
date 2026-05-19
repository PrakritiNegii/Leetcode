class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int> st;

        for(int i=0; i<n1; i++)
          st.insert(nums1[i]);

        for(int i=0; i<n2; i++)
         {
          if(st.count(nums2[i])!=0) return nums2[i];
         }

        return -1;
    }
};