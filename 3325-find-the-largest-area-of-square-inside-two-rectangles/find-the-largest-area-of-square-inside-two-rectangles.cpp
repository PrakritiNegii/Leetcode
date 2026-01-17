class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        long long area = 0;
        for(int i=0; i<n-1; i++) 
         {
          int x11 = bottomLeft[i][0];
          int x12 = topRight[i][0];
          int y11 = bottomLeft[i][1];
          int y12 = topRight[i][1];

          for(int j=i+1; j<n; j++)
           {
            int x21 = bottomLeft[j][0];
            int x22 = topRight[j][0];
            int y21 = bottomLeft[j][1];
            int y22 = topRight[j][1];

            long long xBtm = max(x11,x21);
            long long xTop = min(x12,x22);

            if(xTop<=xBtm) continue;

            long long yBtm = max(y11,y21);
            long long yTop = min(y12,y22);

            if(yTop<=yBtm) continue;

            long long x = xTop - xBtm;
            long long y = yTop - yBtm;

            long long tempArea;
            if(x<y) tempArea = x*x;
            else tempArea = y*y;

            area = max(area,tempArea);
           }

         }

        return area;
    }
};