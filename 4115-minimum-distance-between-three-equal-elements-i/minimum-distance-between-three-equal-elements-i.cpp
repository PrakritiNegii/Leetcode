class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return -1;

        unordered_map<int,int> map;
        for(int i=0; i<n; i++)
          map[nums[i]]++;

        int minDist = INT_MAX;
        for(int i=0; i<n; i++)
         {
          if(map[nums[i]]<3) continue;
          int i1 = i, j1 = -1, k1 = -1;
          for(int j=i+1; j<n; j++)
           {
            if(nums[j]==nums[i])
             {
              if(j1==-1) j1 = j;
              else k1 = j; 
             }

            if(j1!=-1 && k1!=-1) break;
           }
          int dist = abs(i1-j1) + abs(j1-k1) + abs(k1-i1);
          minDist = min(minDist,dist);
          map[nums[i]]--;
         }

        if(minDist==INT_MAX) return -1;
        return minDist;
    }
};