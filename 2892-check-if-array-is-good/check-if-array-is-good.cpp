class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i=0; i<n; i++)
          maxi = max(nums[i],maxi);
         
        vector<int> count(maxi+1,0);

        for(int i=0; i<n; i++)
         {
          count[nums[i]]++;
         }

        if(count[maxi]!=2) return false;

        for(int i=1; i<maxi; i++)
         {
          if(count[i]!=1) 
            return false;
         }
        
        return true;
    }
};