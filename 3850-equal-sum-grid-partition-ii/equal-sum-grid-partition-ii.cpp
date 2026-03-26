class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        unordered_map<long long, long long> first;
        unordered_map<long long, long long> second;

        long long total = 0LL;

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            total += grid[i][j];
            second[grid[i][j]]++;
           }
         }

        long long hfirst = 0LL, hsecond = 0LL;
        for(int i=0; i<n-1; i++)
         {
          for(int j=0; j<m; j++)
           {
            hfirst += grid[i][j];
            first[grid[i][j]]++;
            second[grid[i][j]]--;
            if(second[grid[i][j]]==0) second.erase(grid[i][j]);
           }
          hsecond = total - hfirst;
          if(hfirst==hsecond) return true;

          long long search;
          if(hfirst>hsecond)
           {
            search = hfirst - hsecond;
            if(m==1)
             {
              if(grid[0][0]==search || grid[i][0]==search) return true;
             }
            else if(i==0) 
             {
              if(grid[i][0]==search || grid[i][m-1]==search) return true;
             }
            else
             {
              if(first[search]>0) return true;
             }
           }
          else
           {
            search = hsecond - hfirst;
            if(m==1)
             {
              if(grid[n-1][0]==search || grid[i+1][0]==search) return true;
             }
            else if(i+1==n-1) 
             {
              if(grid[i+1][0]==search || grid[i+1][m-1]==search) return true;
             }
            else
             {
              if(second[search]>0) return true;
             }
           }
         }

        first.clear(); second.clear();
        for(int j=0; j<m; j++)
         {
          for(int i=0; i<n; i++)
           {
            second[grid[i][j]]++;
           }
         }

        long long vfirst = 0LL, vsecond = 0LL;
        for(int j=0; j<m-1; j++)
         {
          for(int i=0; i<n; i++)
           {
            vfirst += grid[i][j];
            first[grid[i][j]]++;
            second[grid[i][j]]--;
            if(second[grid[i][j]]==0) second.erase(grid[i][j]);
           }
          vsecond = total - vfirst;
          cout<<vfirst<<"\thh\t"<<vsecond<<endl;
          if(vfirst==vsecond) return true;
          
          long long search;
          if(vfirst>vsecond)
           {
            search = vfirst - vsecond;
            if(n==1)
             {
              if(grid[0][0]==search || grid[0][j]==search) return true;
             }
            else if(j==0) 
             {
              if(grid[0][j]==search || grid[n-1][j]==search) return true;
             }
            else
             {
              if(first[search]>0) return true;
             }
           }
          else
           {
            search = vsecond - vfirst;
            if(n==1)
             {
              if(grid[0][m-1]==search || grid[0][j+1]==search) return true;
             }
            else if(j+1==m-1) 
             {
              if(grid[0][j+1]==search || grid[n-1][j+1]==search) return true;
             }
            else
             {
              if(second[search]>0) return true;
             }
           }
         }


        return false;
    }
};