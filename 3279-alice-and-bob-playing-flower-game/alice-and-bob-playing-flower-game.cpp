class Solution {
public:
    long long flowerGame(int n, int m) {
        long long pairs=0;
        int even, odd;
        if(m%2==0)
         {
          even = odd = m/2;
         }
        else
         {
          even = m/2;
          odd = even + 1;
         }
        for(int i=1; i<=n; i++)
         {
          if(i%2==0) pairs = pairs + odd;
          else pairs = pairs + even;
         }
        return pairs;
    }
};

// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         long long pairs=0;
//         for(int i=1; i<=n; i+=2)
//          {
//           for(int j=i+1; j<=m; j++)
//             pairs++;
//          }
//         for(int i=1; i<=m; i+=2)
//          {
//           for(int j=i+1; j<=n; j++)
//             pairs++;
//          }
//         return pairs;
//     }
// };

