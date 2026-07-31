class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a, const string &b)
         {
          return a.length() < b.size();
         });
         /*
         Use <, not <=
         std::sort requires the comparator to define a strict weak ordering.

         That means:

         cmp(a, a) must always be false.
         If cmp(a, b) is true, then cmp(b, a) must be false.
         */

        int n = words.size();

        vector<int> lis(n,1);
        int maxLis = 1;
        for(int i=0; i<n; i++)
         {
          for(int j=0; j<i; j++)
           {
            if(words[i].size()-1 != words[j].size()) 
              continue;

            string a = words[i];
            string b = words[j];

            int difference = 0;
            int x=0, y=0;
            while(x<a.size() && difference<=1)
             {
              if(y==b.size() || a[x]!=b[y])
               {
                difference++;
               }
              else y++;
              x++;
             }
             
            if(difference==1)
             {
              lis[i] = max(lis[i],lis[j]+1);
             }
           }
          maxLis = max(maxLis,lis[i]);
         }

      return maxLis;
    }
};