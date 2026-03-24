class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int MOD = 12345;
       int m = grid.size();
       int n = grid[0].size();

       long long prefixProd = 1LL;
       long long suffixProd = 1LL;

       vector<vector<int>> p(m,vector<int>(n,0));

       for(int i=0; i<m; i++)
        {
         for(int j=0; j<n; j++)
          {
           p[i][j] = prefixProd;
           prefixProd = (prefixProd % MOD) * (grid[i][j] % MOD);
          }
        }

       for(int i=m-1; i>=0; i--)
        {
         for(int j=n-1; j>=0; j--)
          {
           p[i][j] = ((p[i][j] % MOD) * (suffixProd % MOD)) % MOD;
           suffixProd = (suffixProd % MOD) * (grid[i][j] % MOD);
          }
        }

       return p;
    }
};