class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int d5 = 0, d10 = 0, d20 = 0;

       for(int i=0; i<bills.size(); i++)
        {
         int val = bills[i];

         if(val==5) d5++;
         else if(val==10)
                {
                 if(d5==0) return false;
                 d10++; d5--;
                }
              else
                {
                 if(d5==0) return false;
                 if(d10==0)
                  {
                   d5-=3;
                   if(d5<0) return false;
                  }
                 else
                  {
                   d10--;
                   d5--;
                  }
                 d20++;
                }
        } 
      return true;
    }
};