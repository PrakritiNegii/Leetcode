class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int sizeQ = queries.size();
        int sizeD = dictionary.size();
        int n = queries[0].size();

        vector<string> ans;

        for(int i=0; i<sizeQ; i++)
         {
          string q = queries[i];
          for(int j=0; j<sizeD; j++)
           {
            string d = dictionary[j];
            int edits = 0;
            for(int k=0; k<n; k++)
             {
              if(q[k]!=d[k]) edits++;
              if(edits>2) break;
             }
            if(edits<=2) 
             {
              ans.push_back(q);
              break; //one match is enough to push the query
             }
           }
         }

        return ans;
    }
};