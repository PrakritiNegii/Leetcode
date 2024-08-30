class Solution {
    public String addBinary(String a, String b) {
       int la = a.length()-1;
       int lb = b.length()-1;
       int sum, carry=48;
       int x, y;
       String c="", res="";
       while(la>-1 || lb>-1) 
        {
          if(la<0)
            { x=48; y=b.charAt(lb); }
          else if(lb<0)
                 { x=a.charAt(la); y=48; }
               else { x=a.charAt(la); y=b.charAt(lb);}

          sum = x^y^carry;
          carry = (x&y)|(y&carry)|(x&carry); 

          c=c+(char)sum;
          la--;
          lb--;
        }
      if(carry==49) c=c+(char)carry; 
      int lc = c.length();
      while(lc>0)
       {
        res = res + c.charAt(lc-1);
        lc--;
       }
      return res;
    }
}