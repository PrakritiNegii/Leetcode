class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();

        vector<int> prev(m+1,0), curr(m+1,0);

        for(int j=1; j<=m; j++) //where i is 0
          prev[j] = j;

        for(int i=1; i<=n; i++)
         {
          curr[0] = i; //when j is 0
          for(int j=1; j<=m; j++)
           {
            if(w1[i-1]==w2[j-1]) 
              curr[j] = prev[j-1];
            else
             {
              int rem = 1 + prev[j];
              int ins = 1 + curr[j-1];
              int rep = 1 + prev[j-1];

              curr[j] = min({rem,ins,rep});
             }
           }
          prev = curr;
         }

        return prev[m];
    }
};