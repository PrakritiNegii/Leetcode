class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(n==1) return 0;
        if(n==2)
         {
          if(s[0]<=s[1]) return 0;
          return -1;
         } 
        
        int minRank = INT_MAX;
        int maxRank = INT_MIN;

        int rank1 = s[0]-97;
        bool dupOf1 = false;
        int rankn = s[n-1]-97;
        bool dupOfn = false;

        int prevRank = rank1;

        bool sortedAsc = true;
        for(int i=1; i<n-1; i++)
            {
             int rank = s[i] - 97;
             if(rank<prevRank) sortedAsc = false;
             if(rank==rank1) dupOf1 = true;
             if(rank==rankn) dupOfn = true;

             prevRank = rank;
             if(rank < minRank) minRank = rank;
             if(rank > maxRank) maxRank = rank;
            }

        if(rankn<prevRank) sortedAsc = false;

        if(sortedAsc) return 0;

        maxRank = max(maxRank,rank1);
        maxRank = max(maxRank,rankn);

        minRank = min(minRank,rank1);
        minRank = min(minRank,rankn);

        if(rank1==minRank || rankn==maxRank) return 1;

        if(rank1==maxRank && rankn==minRank && !dupOf1 && !dupOfn) return 3;

        return 2;
    }
};