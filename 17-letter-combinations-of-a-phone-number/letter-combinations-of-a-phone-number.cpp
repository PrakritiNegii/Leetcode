class Solution {
public:
    vector<string> letterCombinations(string digits) {
      if(digits.size()==0) return {};
      vector<string> ans;
      generate(digits,ans,"",0);
      return ans;
    }
    void generate(string digits, vector<string>& ans, string str, int i)
     {
      if(i==digits.size())
       {
        // cout<<"HERE"<<str<<endl;
        ans.push_back(str);
        return;
       }
      int x = (int) digits[i] - 48;
      int l = 3;
      int y;
      if(x==7) l = 4;
      if(x<8)
       {
        for(int j=0; j<l; j++)
         {
          y = (x-2)*3;
          string temp = str + (char)(97+y+j);
          generate(digits, ans, temp, i+1);
          temp = "";
         }
       }
      else
       {
        if(x==8)
         {
          l = 3;
          y = 19;
         }
        else 
         {
          l = 4;
          y = 22;
         }
        for(int j=0; j<l; j++)
         {
          string temp = str + (char)(97+y+j);
          generate(digits, ans, temp, i+1);
          temp = "";
         }
       }
     }
};