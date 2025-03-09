class Solution {
public:
    bool isValid(string s) {
        stack <char> c;
        int i=0;
        while(s[i]!='\0')
         {
          switch(s[i])
           {
            case '(': 
            case '{':
            case '[':
              c.push(s[i]);
             break;
            
            case ')': 
              if(c.empty() || c.top()!='(')
                return false;
              c.pop();
             break;
            case '}':
              if(c.empty() || c.top()!='{')
                return false;
              c.pop();
             break;
            case ']':
              if(c.empty() || c.top()!='[')
                return false;
              c.pop();
             break;
           }
          i++;
         }
        if(c.empty())
          return true;
        else 
          return false;
    }
};