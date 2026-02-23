class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.size();

        int opening = 0;
        for(int i=0; i<n; i++)
         {
          if(!opening)
           {
            opening++;
           }
          else if(s[i]=='(')
                {
                 opening++;
                 ans += '(';
                }
          if(s[i]==')')
           {
            opening--;
            if(!opening) continue;
            ans += ")";
           }
         }

        return ans;
    }
};