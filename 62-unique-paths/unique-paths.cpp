class Solution {
public: 
    int uniquePaths(int m, int n) {
         vector<int>dp (n,0);
         
         for(int i=0; i<m; i++)
          {
           int left; //initially for each row there is no left
           vector<int> temp(n,0);
           for(int j=0; j<n; j++)
            {
             if(i==0 && j==0) temp[0] = 1;  //starting cell
             //check can you reach this particular cell from the top or from the left
             int newr = i-1; //check top
             int newc = j-1; //check left

             if(newr>=0) temp[j] += dp[j];
             if(newc>=0) temp[j] += left;

             left = temp[j];
            }
           dp = temp;
          }
         return dp[n-1];
    }
};