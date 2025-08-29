// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         long long pairs=0;
//         int even, odd;
//         if(m%2==0)
//          {
//           even = odd = m/2;
//          }
//         else
//          {
//           even = m/2;
//           odd = even + 1;
//          }
//         for(int i=1; i<=n; i++)
//          {
//           if(i%2==0) pairs = pairs + odd;
//           else pairs = pairs + even;
//          }
//         return pairs;
//     }
// };

class Solution {
public:
    long long flowerGame(int n, int m) 
    { return (long long)m * n / 2; }
};