#include <iostream>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
      int count = 1;

      int i = 1;
      int num = pow(2,i)-1;

      while(num<=n)
       {
        count++;
        i++;
        num = pow(2,i)-1;
       } 
      
        return count;
    }
};