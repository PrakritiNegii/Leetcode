class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++)
         {
          if(st.empty())
           {
            st.push(s[i]);
           }
          else if(s[i]=='(')
                {
                 st.push('(');
                 ans += '(';
                }
          if(s[i]==')')
           {
            char c = st.top();
            st.pop();
            if(st.empty()) continue;
            ans += ")";
           }
         }

        return ans;
    }
};