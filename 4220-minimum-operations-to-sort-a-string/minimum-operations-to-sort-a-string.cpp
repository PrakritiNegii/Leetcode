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

        //if maxRank and minRank are equal all elements are equal hence sorted
        

        //if minimum is at its correct place, maximum is at its correct place or both are at their respective correct places string can be sorted by sorting just one half or just the middle portion
        if(rank1==minRank) return 1;
        if(rankn==maxRank) return 1;

       //if minimum and maximum are at opposite places they will require three swaps to sort the string. However, if minRank or maxRank have duplicates present in the middle sorting will require only 2 swaps as in the first swap one of the minRank or maxRank will reach its correct position and after that only 1 sort is required
        if(rank1==maxRank && rankn==minRank && !dupOf1 && !dupOfn) return 3;

// in the case that minRank and maxRank are not on either ends. Then one sort will position either the minRank at its correct position or maxRank at its correct position. After that only 1 sort is required to sort the complete string.
        return 2;
    }
};