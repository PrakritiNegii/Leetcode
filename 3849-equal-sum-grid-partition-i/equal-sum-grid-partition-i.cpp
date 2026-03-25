class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        unordered_set<long long> horizontal;
        unordered_set<long long> vertical;

        long long h = 0LL, v = 0LL;

        for(int i=0; i<grid.size(); i++)
         {
          for(int j=0; j<grid[0].size(); j++)
           {
            h += grid[i][j];
           }
          horizontal.insert({h});
         }

        for(int j=0; j<grid[0].size(); j++)
         {
          for(int i=0; i<grid.size(); i++)
           {
            v += grid[i][j];
           }
          vertical.insert({v});
         }

        long double half_h = h/2.0;
        long double half_v = v/2.0;

        long long hh = h/2;
        long long hv = v/2;

        if(half_h == hh)
         {
          if(horizontal.find(hh) != horizontal.end()) return true;
         }

        if(half_v == hv)
         {
          if(vertical.find(hv) != vertical.end()) return true;
         }

        return false;
    }
};