class Robot {
public:
    int m, n;
    int x=0, y=0;

    bool is_x = true;
    int sign = 1; 

    Robot(int width, int height) {
       m = width-1;
       n = height-1; 
    }
    
    void step(int num) {
      if(num==0) return;
      int peri = 2*m + 2*n;
      num %= peri;
      if(num==0) num = peri;  //as direction changes from what it was initially
      while(num)
       {
        bool validStep = false;
        if(is_x)
         {
          if(sign>0 && x<m) 
           {
            if(x+num <= m) 
             {
              x = x+num;
              return;
             }
            else
             {
              num -= (m-x);
              x = m;
             }
            validStep = true;
           }
          else if(sign<0 && x>0)
           {
            if(x-num >= 0) 
             {
              x = x-num;
              return;
             }
            else
             {
              num -= x;
              x = 0;
             }
            validStep = true;
           }
         }
        else
         {
          if(sign>0 && y<n)
           {
            if(y+num <= n) 
             {
              y = y+num;
              return;
             }
            else
             {
              num -= (n-y);
              y = n;
             }
            validStep = true;
           }
          else if(sign<0 && y>0)
           {
            if(y-num >= 0) 
             {
              y = y-num;
              return;
             }
            else
             {
              num -= y;
              y = 0;
             }
            validStep = true;
           }
         }

        if(validStep)
         {
          continue;
         }

        //incase robot is moving out of bounds
        if(is_x)
         {
          is_x = false;
         }
        else
         {
          is_x = true;
          sign *= -1;
         }
       }
    }
    
    vector<int> getPos() {
       return {x,y}; 
    }
    
    string getDir() {
        if(is_x)
         {
          if(sign>0) return "East";
          else return "West";
         }
        else
         {
          if(sign>0) return "North";
          else return "South";
         }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */