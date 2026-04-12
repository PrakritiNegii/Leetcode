class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        unordered_set<int> zeroes;
        for(int i=0; i<n; i++)
         {
          if(nums[i]==0) zeroes.insert(i);
         }

        if(zeroes.size()==0) return true;

        for(int i=n-2; i>=0; i--)
         {
          if(nums[i]==0) continue;
          int j = i+nums[i];
          if(j>=n-1) continue;
          while(j>i && zeroes.count(j)!=0)
           {
            j--;
           }
          if(j==i) zeroes.insert(j);
         }

        if(zeroes.count(0)!=0) return false;
      return true;
    }
};