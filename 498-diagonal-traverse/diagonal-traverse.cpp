class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
     int r=0, c=0, rsize=mat.size(), csize=mat[0].size();
     vector<int> res;
     bool up = true;
     while(r<rsize && c<csize)
      {
       cout<<r<<"    "<<c<<endl;
       res.push_back(mat[r][c]);
       if(up==true)
        {
          if(r-1<0 || c+1>=csize)
           {
             up = false;
             if(c+1>=csize)
              r = r + 1;
             else
              c = c + 1;
           }
         else
           {
             r = r - 1;
             c = c + 1;
           }
        }
       else
        {
          if(r+1>=rsize || c-1<0)
           {
             up = true;
             if(r+1>=rsize)
              c = c + 1;
             else
              r = r + 1;
           }
         else
           {
             r = r + 1;
             c = c - 1;
           }
        }
      }   
     return res;     
    }
};