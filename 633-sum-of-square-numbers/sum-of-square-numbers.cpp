class Solution {
public:
    bool judgeSquareSum(int c) {
     int left = 0, right = floor(sqrt(c));

     while(left<=right)
      {
       long long val = (long long) left*left + (long long) right * right;
       if(val==c) return true;
       if(val>c) right--;
       else left++;
      }   

     return false;
    }
};