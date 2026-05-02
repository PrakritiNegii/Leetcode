class Solution {
public:
    int rotatedDigits(int n) {
       int count = 0;
       for(int i=2; i<=n; i++) 
        {
         int num = i;
         bool valid = false;
         bool invalid = false;
         while(num>0)
          {
           int d = num % 10;
           if(d==2 || d==5 || d==6 || d==9)
              valid = true;
           else if(d==3 || d==4 || d==7)
                 {
                  invalid = true;
                  break;
                 }
           num /= 10;
          }
          if(invalid) continue;
          if(valid) count++;
        }
      return count;
    }
};