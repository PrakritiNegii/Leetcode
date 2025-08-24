class Solution {
public:
    vector<string> addOperators(string num, int target) {
      vector<string> ans;
      check(num,0,0,0,"",target,ans);
      return ans;  
    }
    void check(string &num, int pos, long long lastPart, long long lastVal, string exp, int &target, vector<string> &ans)
     {
      if(pos>=num.size())
       {
        if(lastVal==target)
          ans.push_back(exp);
        return;
       }

      for(int i = pos; i<num.size(); i++)
       {
        if (num[pos] == '0' && i > pos) break;  // avoid leading zeros
        //very imp to avoid leading zeroes

        string ss = num.substr(pos,i-pos+1);
        long long n = stoll(ss);
        
        if(pos==0) 
          check(num,i+1,n,n,exp+ss,target,ans);
        else
         {
          //for add
          check(num, i+1, n, lastVal+n, exp+'+'+ss, target, ans);

          //for subtract
          check(num, i+1, -n, lastVal-n, exp+'-'+ss, target, ans);
          /*
          For subtraction, you must pass -n as lastPart so future multiplications work correctly:*/

          //for multiply
          check(num, i+1, n*lastPart, lastVal-lastPart + lastPart*n, exp+'*'+ss, target, ans);
          /*For multiplication, lastPart should be multiplied and stored for the next recursive step.
Otherwise, future multiplications won’t chain correctly.*/
         }
       }
     }
};