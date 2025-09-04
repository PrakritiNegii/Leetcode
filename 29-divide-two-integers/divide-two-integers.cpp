class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1)
         {
          if(dividend==INT_MIN) return INT_MAX;
          return dividend*-1;
         }

        if(dividend==INT_MAX && divisor==INT_MIN) return 0;

        int sign = 0, minDend = 0, minDiv = 0;
        if((dividend<0 && divisor>=0)||(dividend>=0 && divisor<0))
         {
          sign = 1;
         }
        if(dividend==INT_MIN) 
           {
            dividend = INT_MAX;
            minDend = 1;
           }  
        if(divisor==INT_MIN)
           {
            divisor = INT_MAX;
            minDiv = 1;
           }
        if(dividend<0) dividend*=-1;
        if(divisor<0) divisor*=-1;
        
        string dend = to_string(dividend); //one that is divided
       // string sor = divisor; //one that divides

        int quotient = 0;

        int i=0, j=0;
        int currDend = 0;
        while(j<dend.size())
         {
          currDend = currDend*10 + (dend[j]-'0');
          if(currDend<divisor) 
           {
            quotient = quotient * 10;
            j++;
            continue;
           }
          int c = 0;
          long long res = 0;
          while(res<=currDend)
           {
            res += divisor;
            c++;
           }
          res -= divisor;
          c--;

          currDend = currDend - res;
          quotient = quotient * 10 + c;

          j = j+1;
          i = j;
         }

      if(dividend==INT_MAX && minDend==1) //dividend is INT_MIN
       {
        if(currDend==divisor-1)  //currDend is also like remainder
          quotient++;
       }

      if(sign == 0)
        return quotient; 
      else 
        return quotient*-1;
    }
};