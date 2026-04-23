class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, vector<int> > mp;
      
        for(int i=0; i<n; i++)
         {
          int val = nums[i];
          mp[val].push_back(i);
         }

        vector<long long> count(n,0);

        for(auto val : mp)
         {
          int size = val.second.size();
          long long left = 0LL, right = 0LL;
          for(int j=1; j<size; j++)
            right += (long long) val.second[j];

          int leftSize = 0, rightSize = size-1;
          for(int j=0; j<size; j++)
           {
            int currPos = val.second[j];
            count[currPos] += abs((long long) currPos*leftSize - left);
            count[currPos] += abs((long long) currPos*rightSize - right);

            left += val.second[j];
            if(j<size-1) right -= val.second[j+1];

            leftSize++; rightSize--;
           }
         }
        return count;
    }
};