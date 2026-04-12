class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int left = 0, right = 0, star = 0;

        for(int i=0; i<n; i++)
         {
          if(s[i]=='(') left++;
          else if(s[i]==')') right++;
               else star++;

          if(left<right)
           {
            if(star==0) return false;
            star--; left++;
           }
         }

        left = 0, right = 0, star = 0;
        for(int i=n-1; i>=0; i--)
         {
          if(s[i]=='(') left++;
          else if(s[i]==')') right++;
               else star++;

          if(right<left)
           {
            if(star==0) return false;
            star--; right++;
           }
         }

        return true;
    }
};