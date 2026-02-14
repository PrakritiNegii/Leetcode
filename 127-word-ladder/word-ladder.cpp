class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<pair<string,int>,int>> q; //word, index, level

        vector<int> visit(wordList.size(),0);
        int wordSize = beginWord.size();

        q.push({{beginWord,-1},1});
        string currWord = beginWord;

        while(!q.empty())
         {
          currWord = q.front().first.first;
          int ind = q.front().first.second;
          int level = q.front().second;
          q.pop();
          for(int i=0; i<wordList.size(); i++)
           {
            int d = 0;
            if(visit[i]!=0 && visit[i]<=level) continue;
            for(int j=0; j<wordSize; j++)
             {
              if(wordList[i][j]!=currWord[j])
               {
                 d++;
               }
             }
            if(d==1 && (visit[i]==0 || visit[i]>level))
             {
              q.push({{wordList[i],i},level+1});
              visit[i] = level+1;
              if(wordList[i]==endWord) return level+1;
             }
           }
         }
       return 0;
    }
};