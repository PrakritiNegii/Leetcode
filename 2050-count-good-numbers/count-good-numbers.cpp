#define MOD 1000000007
class Solution {
public:
    int countGoodNumbers(long long n) {
        // long long even = 0;
        // long long prime = 0;
        // if(n%2==0) 
        //  {
        //   even = prime = n/2;
        //  }
        // else
        //  {
        //   even = n/2 + 1;
        //   prime = n/2;
        //  }
        long long even = (n+1)/2;
        long long prime = n/2;

        long long res = ((power(5,even) % MOD) * (power(4,prime) % MOD)) % MOD;
        return res;
      }
    long long power(int x, long long n) //x^n
     {
      if(n==0) return 1;
      if(n==1) return x;
      if(n%2!=0) 
       {
        return (x * power(x,n-1)) % (1000000007);
       }
      long long val = power(x,n/2);
      val = val % (1000000000+7);
      return (val * val) % (1000000007);
     }
};