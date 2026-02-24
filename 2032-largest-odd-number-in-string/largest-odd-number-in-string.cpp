class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        bool odd = false;
        for(int i=num.size()-1; i>=0; i--)
         {
          if(odd==true) 
           {
            ans += num[i];
            continue;
           }
          int c = num[i]; //0 to 9 is 48 to 57, the corresponding ascii values are odd too
          if(c%2!=0) 
           {
            odd = true;
            ans += (char) c;
           }
         }

        if(odd==false) return "";

        reverse(ans.begin(),ans.end());
        return ans;
    }
};