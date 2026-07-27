class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end(),greater<int>());
          
        vector<int> maxSubset;
        
        for(int i=0; i<n; i++)
         {
          vector<vector<int>> ss;
          ss.push_back({nums[i]});

          int maxSize = 1;
          int maxIdx = 0;

          for(int j=i+1; j<n; j++)
           {
            bool newSubset = true;

            for(int k=0; k<ss.size(); k++)
             {
              int last = ss[k].back();
              if(last%nums[j]==0)
               {
                ss[k].push_back(nums[j]);
                int size = ss[k].size();
                if(size>maxSize)
                 {
                  maxSize = size;
                  maxIdx = k;
                 }
                newSubset = false;
               }
             }

            if(nums[i]%nums[j]==0)
                ss.push_back({nums[i],nums[j]});
           }

          if(maxSize>maxSubset.size())
            maxSubset = ss[maxIdx];
         }

        return maxSubset;
    }
};