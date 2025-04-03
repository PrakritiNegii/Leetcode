// class Solution {
// public:
//     int mySqrt(int x) {
//         int num = x;
//         int n = 1;
//         int count = 0;
//         while(n<=num)
//          {
//           count++;
//           num=num-n;
//           n+=2;
//          }
//         return count;
//     }
// };
class Solution {
    public:
      int mySqrt(int x) 
      {
       int l = 1, r = x;
       int res = 0;
       while(l<=r)
        {
          long long mid = l + (r-l)/2;
          if(mid*mid==x)
            return mid;
          else if(mid*mid < x)
                {
                 res = mid;
                 l = mid+1;
                }
               else
                {
                 r = mid-1;
                }
        }
       return res;
      }
};