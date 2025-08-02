class Solution {
private:
  bool check(string s)
   {
    int i = 0, j = s.size()-1;
    bool flag = true;
    while(i<j)
     {
      if(s[i]!=s[j])
       {
        flag = false;
        break;
       }
      i++, j--;
     }
    return flag;
   }
public:
    vector<vector<string>> partition(string s) 
     {
      vector<vector<string>> ans;
      vector<string> str;
      generate(s,ans,str,0);
      return ans;
     }

    void generate(string s, vector<vector<string>>& ans, vector<string>& vec, int i)
     {
      if(i==s.size())
       {
        ans.push_back(vec);
        return;
       }

      string temp = "";
      for(int j=i; j<s.size(); j++)
       {
        temp = temp + s[j];
        if(check(temp)==1) 
         {
          vec.push_back(temp);
         }
        else 
          continue;

        cout<<temp<<endl;

        int add = temp.size();
        generate(s,ans,vec,i+add);
        vec.pop_back();

       }
     }
};