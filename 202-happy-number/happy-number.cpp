class Solution {
public:
    bool isHappy(int n) {
       unordered_set <int> visited;
       visited.insert(n);
       int num = n;

       while(1) 
        {
         int temp = num;
         num = 0;
         while(temp>0)
          {
           int d = temp % 10;
           num += d*d;
           temp /= 10;
          }
         if(num==1) return true;
         if(visited.count(num)!=0) break;
         visited.insert(num);
        }

       return false;
    }
};