class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int MOD = 12345;
       int m = grid.size();
       int n = grid[0].size();
       vector<int> prefix(n*m);
       vector<int> suffix(n*m);

       long long prefixProd = 1LL;
       long long suffixProd = 1LL;

       for(int i=0, j=n*m-1; i<n*m, j>=0; i++, j--)
        {
         prefix[i] = prefixProd;
         prefixProd = (prefixProd % MOD) * (grid[i/n][i%n] % MOD);

         suffix[j] = suffixProd;
         suffixProd = (suffixProd % MOD) * (grid[j/n][j%n] % MOD);
        }

       vector<vector<int>> p(m,vector<int>(n,0));

       for(int i=0; i<m; i++)
        {
         for(int j=0; j<n; j++)
          {
           int index1D = i*n + j;
           p[i][j] = ( (prefix[index1D] % MOD) * (suffix[index1D] % MOD) ) % MOD;
          }
        }

       return p;
    }
};