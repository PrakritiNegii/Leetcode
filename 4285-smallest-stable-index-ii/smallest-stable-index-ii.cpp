class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int n = nums.size();

        vector<int> maxEl(n);
        vector<int> minEl(n);
        for(int i=0; i<nums.size(); i++)
            {
              maxi = max(maxi,nums[i]);
              maxEl[i] = maxi;

              mini = min(mini,nums[n-i-1]);
              minEl[n-i-1] = mini; 
            }

        for(int i=0; i<nums.size(); i++)
            {
              int ma = maxEl[i];
              int mi = minEl[i];

              int val = ma - mi;

              if(val<=k) return i;
            }
        
        return -1;
    }
};