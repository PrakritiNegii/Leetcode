class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDFirst = INT_MIN;
        int maxDSecond = INT_MIN;

        for(int i=n-1; i>=0; i--)
         {
          if(colors[0]!=colors[i])
            {
             maxDFirst = i;
             break;
            }
         }

        for(int i=0; i<n; i++)
         {
          if(colors[n-1]!=colors[i])
            {
             maxDSecond = (n-1-i);
             break;
            }
         }

        return max(maxDFirst,maxDSecond);
    }
};