class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";

        int openingBrackets = 0;

        for(int i=0; i<n; i++)
         {
          if(openingBrackets==0) //Found first opening bracket in a decomposition
           {
            openingBrackets+=1; //Don't add the outermost bracket in the answer
           }
          else if(s[i]=='(') //if openingBrackets!=0 and bracket is opening 
                {
                 ans += '('; //add bracket in answer 
                 openingBrackets+=1; //increase the count of opening brackets
                }
          if(s[i]==')') //if bracket found is closing
           {
            openingBrackets-=1; //a set of brackets is found
            if(!openingBrackets) //set of brackets is outermost, don't add in answer
              continue;
            ans += ")"; //if set is not outermost add it in the answer
           }
         }

        return ans;
    }
};