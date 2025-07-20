class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       generate(n,res,"",0,0);
       return res; 
    }
    void generate(int n, vector<string> &res, string s, int i, int j)
     {
      if(i==n && j==n)
       {
        res.push_back(s);
        return;
       }
      if(i<n || j<n)
       {
        if(i<n)
          generate(n,res,s+'(',i+1,j);
        if(i-j>0)
          generate(n,res,s+')',i,j+1);
       }
     }
};