class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      if(n==0) return true;

      int size = flowerbed.size();

      if(size==1)
       {
        if(flowerbed[0]==0) return true;
        else return false;
       }

      for(int i=0; i<size; i++)
       {
        if(!flowerbed[i] && (i==0 || !flowerbed[i-1]) && (i==size-1 || !flowerbed[i+1]))
         {
          flowerbed[i] = 1;
          n--;
         }
        if(n==0)
          return true;
       }

      return false;
    }
};