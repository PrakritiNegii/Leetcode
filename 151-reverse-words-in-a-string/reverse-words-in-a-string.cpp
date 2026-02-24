class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        stack<char> st;

        int i=n; 
        while(i>0)
         {
          i--;
          if((s[i]==' ' && i==n-1) || (s[i]==' ' &&  s[i+1]==' ')) 
            continue;
          if(s[i]==' ')
           {
            cout<<i<<endl;
            if(ans.size()!=0) ans += ' ';
            while(!st.empty())
             {
              ans += st.top();
              st.pop();
             }
           }
          else 
            st.push(s[i]);
         }
        if(!st.empty() && ans.size()!=0) ans += ' ';
        while(!st.empty())
             {
              ans += st.top();
              st.pop();
             }
        return ans;
    }
};