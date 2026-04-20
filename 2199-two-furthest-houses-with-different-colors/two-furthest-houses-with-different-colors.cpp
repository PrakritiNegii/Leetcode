class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxD = INT_MIN;

        for(int i=0; i<n; i++)
         {
          for(int j=n-1; j>=i; j--)
           {
            if(colors[i]!=colors[j]) 
              maxD = max(maxD,abs(j-i));

            if(maxD>=(n-i)) return maxD;
           }
         }

        return maxD;
    }
};