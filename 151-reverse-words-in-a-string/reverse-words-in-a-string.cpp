class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        string temp = "";
        for(int i=n-1; i>=0; i--)
         {
          if(s[i]==' ' && temp.empty()) continue;
          if(s[i]==' ')
           {
            reverse(temp.begin(),temp.end());
            
            if(!ans.empty()) ans+=' ';
            ans += temp;
            temp = "";
           }
          else
           {
            temp += s[i];
           }
         }

        reverse(temp.begin(),temp.end());
        if(!temp.empty()) 
         {
          if(!ans.empty()) ans += ' ';
          ans += temp;
         }
        return ans;
    }
};