class Solution {
public:
    void move(int& x, int& y, int axis, int sign, int length, set<pair<int,int>>& st)
     {
      bool is_y = true;
      if(axis==0) is_y = false;

      while(length!=0)
       {
        if(sign>0)
         {
          if(is_y) {y++; if(st.count({x,y})!=0) {y--; return;} }
          else {x++; if(st.count({x,y})!=0) {x--; return;} }
         }
        else
         {
          if(is_y) {y--; if(st.count({x,y})!=0) {y++; return;} }
          else {x--; if(st.count({x,y})!=0) {x++; return;} }
         }
        length--;
       }
     }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
     set<pair<int,int>> st;
     int maxDist = INT_MIN;

     for(int i=0; i<obstacles.size(); i++)
      {
       int x = obstacles[i][0];
       int y = obstacles[i][1];
       st.insert({x,y}); 
      }   

     int x = 0, y = 0;
     int axis = 1; //initially at y axis (index = 1) 
     int sign = 1; //1 for positive
     for(int i=0; i<commands.size(); i++)
      {
       if(commands[i]==-1) //rotate 90 degree right
        {
         if(axis==1) //no change in sign 
          {
           axis = 0;
          }
         else
          {
           axis = 1;
           sign *= -1;
          }
        }
       else if(commands[i]==-2) //rotate 90 degree left
             {
              if(axis==1)  
               {
                axis = 0;
                sign *= -1;
               }
              else //no change in sign
               {
                axis = 1;
               }     
             }
            else
              {
                move(x,y,axis,sign,commands[i],st);
                cout<<x<<"\t"<<y<<endl;
                int dist = x*x + y*y;
                maxDist = max(maxDist,dist);
              }
      }

      return maxDist;
    }
};