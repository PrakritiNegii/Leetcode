class Solution {
public:
    bool canCross(vector<int>& stones) {
       int n = stones.size();

       unordered_map<int,int> hashmap;
       for(int i=0; i<n; i++)
        {
         hashmap.insert({stones[i],i});
        }

       vector< unordered_set<int> > table(n); //not vector<vector<int>> because duplicate jumps increase complexity

       table[0].insert({0});
       for(int i=0; i<n; i++)
        {
         for(int prevk : table[i]) //for each value in table[i-1]
          {
           for(int k=prevk-1; k<=prevk+1; k++)
            {
             if(k<=0) continue;

             int jumpTo = stones[i]+k;
             if(hashmap.count(jumpTo)==0) continue; //does not reach a valid stone
             
             int j = hashmap[jumpTo];
             table[j].insert({k});
            }
          }
        }  

       if(table[n-1].empty()==false) //some path did reach the last stone     
         return true;
       return false;
    }
};