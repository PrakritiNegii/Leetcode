double myPow(double x, long int n) {
    if(x==0) return 0;
       if(n==1) return x;
       if(n>0) 
         {
          if(n%2==0) 
           {
            double val = myPow(x,n/2);
            return val * val;
           }
          else 
           {
            return x * myPow(x,n-1);
           }
         } 
       else if(n<0) return (1/myPow(x,-n));
       return 1;
}