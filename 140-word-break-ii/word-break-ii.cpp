class Solution {
public:
    void sentence(string s, int i, unordered_set<string>& words, string segment, vector<string>& ans) {
        if(i>=s.size())
          {
            ans.push_back(segment);
            return;
          }
        string temp = "";
        for(int j=i; j<s.size(); j++)
         {
          temp += s[j];
          if(words.count(temp)!=0)
            {
             if(i==0) //if(segment=="")
               sentence(s,j+1,words,segment+temp,ans);
             else
               sentence(s,j+1,words,segment+" "+temp,ans);
            } 
         }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words({begin(wordDict),end(wordDict)});

        vector<string> ans;
        sentence(s,0,words,"",ans);
        
        return ans;
    }
};