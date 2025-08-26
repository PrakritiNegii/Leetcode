class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int i = 0;
        double diagSQ = 0, maxdiagSQ = INT_MIN;
        int area = 0, maxarea = INT_MIN;
        for(i=0;i<dimensions.size();i++)
            {
                int a = dimensions[i][0];
                int b = dimensions[i][1];
                diagSQ = a*a + b*b;
                area = a*b;
                if(diagSQ>maxdiagSQ)
                {
                 maxdiagSQ = diagSQ;
                 maxarea = area;
                }
                else if(diagSQ==maxdiagSQ)
                {
                 if(maxarea<area)
                 {
                  maxarea = area;
                 }
                }
            }
        return maxarea;
    }
};