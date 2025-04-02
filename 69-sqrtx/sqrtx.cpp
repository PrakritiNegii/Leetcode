class Solution {
public:
    int mySqrt(int x) {
        int num = x;
        int n = 1;
        int count = 0;
        while(n<=num)
         {
          count++;
          num=num-n;
          n+=2;
         }
        return count;
    }
};