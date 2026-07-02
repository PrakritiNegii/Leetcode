class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);

        for(int i=0; i<n; i++)
         {
          int idx = i+1;
          if(idx%3==0 && idx%5==0) ans[i] = "FizzBuzz";
          else if(idx%3==0) ans[i] = "Fizz";
               else if(idx%5==0) ans[i] = "Buzz";
                    else ans[i] = to_string(idx);
         }

        return ans;
    }
};