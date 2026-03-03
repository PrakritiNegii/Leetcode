class Solution {
public:
    int maxDepth(string s) {
      int n = s.size();
      int maxD = 0;
      int opening = 0;

      int i=0;
      while(i<n)
       {
        if(s[i]=='(') opening++;
        else if(s[i]==')') opening--;

        maxD = max(opening,maxD);
        i++;
       }  

      return maxD;
    }
};