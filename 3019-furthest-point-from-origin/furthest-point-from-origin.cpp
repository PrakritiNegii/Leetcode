class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       int Lcount = 0, Rcount = 0, Scount = 0;
       int n = moves.size();
       for(int i=0; i<n; i++)
        {
         if(moves[i]=='L') Lcount++;
         else if(moves[i]=='R') Rcount++;
              else Scount++;
        } 

       if(Lcount>Rcount)
          return Lcount + Scount - Rcount;
       else
          return Rcount + Scount - Lcount;
    }
};