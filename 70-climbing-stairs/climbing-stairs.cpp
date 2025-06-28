
class Solution {
public:
   unsigned long long climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;

       unsigned long long a = 1;
       unsigned long long b = 2;
     unsigned long long c ;
        while(n!=2)
         {
          c = a+ b;
          a =b ;
          b = c;
          n--;
         }
        return c;
    }};