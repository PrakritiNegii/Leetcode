// class Solution {
// public:
//     int reverse(int x) {
//         long long rev = 0;
//         bool negFlag = false;
//         if(x<0) 
//          {
//           negFlag = true;
//           if(x<=INT_MIN) return 0;
//           //Incase x = INT_MIN, x*-1 > INT_MAX
//           x*=-1; 
//          }
//         while(x>0)
//          {
//           rev = rev*10 + x%10;
//           x/=10;
//          }
//         if(negFlag==true) rev*=-1;
//         if (rev > INT_MAX || rev < INT_MIN) 
//           return 0;
//         else 
//           return rev;
//     }
// };

//Code without long long
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow BEFORE actually updating rev
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

            rev = rev * 10 + digit;
        }
        return rev;
    }
};
