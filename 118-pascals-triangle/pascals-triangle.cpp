class Solution {
public:
    long long nCr(int n, int r)
     {
      long long ans = 1;
      int divisorF = min(r,n-r);
      int i=1;
      while(i<=divisorF)
       {
        ans = (ans*n)/i;
        i++; n--;
       }
      return ans;
     }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PascalTri;
        for(int i=0; i<numRows; i++)
         {
          vector<int> temp(i+1);
          for(int j=0; j<=i; j++)
           {
            temp[j] = nCr(i,j);
           }
          PascalTri.push_back(temp);
         }
        return PascalTri;
     }
};