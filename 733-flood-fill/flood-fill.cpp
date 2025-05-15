class Solution {
public:
    void dfs(vector<vector<int>>& image, int R, int C, int color, int scolor, int sr, int sc)
     {
        int drow[] = {0,0,-1,1};
        int dcol[] = {1,-1,0,0};
        for(int i=0; i<4; i++)
         {
          int newr = sr + drow[i];
          int newc = sc + dcol[i];
          if(newr>=0 && newr<R && newc>=0 && newc<C && image[newr][newc]==scolor)
           {
            image[newr][newc] = color;
            dfs(image,R,C,color,scolor,newr,newc);
           }
       }
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int R = image.size();
       int C = image[0].size();
       if(image[sr][sc]!=color)
        {
         int scolor = image[sr][sc];
         image[sr][sc] = color;
         dfs(image,R,C,color,scolor,sr,sc);
        }
       return image;
    }
};