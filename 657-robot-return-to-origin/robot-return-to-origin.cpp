class Solution {
public:
    bool judgeCircle(string moves) {
        int upDown = 0;
        int rightLeft = 0;

        int i=0;
        int n = moves.size();
        while(i<n)
         {
          if(moves[i]=='U') upDown++;
          else if(moves[i]=='D') upDown--;
               else if(moves[i]=='R') rightLeft++;
                    else if(moves[i]=='L') rightLeft--;
          i++;
         }

        if(!upDown && !rightLeft) return true;
        return false;
    }
};