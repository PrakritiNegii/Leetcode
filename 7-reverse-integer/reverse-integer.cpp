class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        bool negFlag = false;
        if(x<0) 
         {
          negFlag = true;
          if(x<=INT_MIN) return 0;
          //Incase x = INT_MIN, x*-1 > INT_MAX
          x*=-1; 
         }
        while(x>0)
         {
          rev = rev*10 + x%10;
          x/=10;
         }
        if(negFlag==true) rev*=-1;
        if (rev > INT_MAX || rev < INT_MIN) 
          return 0;
        else 
          return rev;
    }
};