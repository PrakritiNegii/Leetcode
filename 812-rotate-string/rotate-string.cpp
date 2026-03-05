class Solution {
public:
    bool rotateString(string s, string goal) {
        int s1 = s.size();
        int s2 = goal.size();

        if(s1!=s2) return false;

        int i=0, j=0; //i for s and j for goal
        while(i<s1 && j<s1)
         {
          if(s[i]!=goal[j]) 
           {
            j++;
            continue;
           } 
          i++;  //i increases only when j matches with it
          int k = (j+1)%s1;
          while(k!=j)
           {
            if(goal[k]!=s[i])
             {
              break;
             }
            k = (k+1)%s1;
            i++;
           }
          if(k==j) return true; //all of the string matched
          i = 0;
          j++;
         }

        return false;
    }
};