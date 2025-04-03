class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int d;
        if(num>999)
         {
          d = num / 1000;
          for(int i=1; i<=d; i++)
            res += 'M';
          num%=1000;
         }
        if(num>99)
         {
          d = num / 100;
          switch(d)
           {
            case 1: case 2: case 3:
              for(int i=1; i<=d; i++)
                res += 'C';
             break;
            case 4:
              res += "CD";
             break;
            case 5: case 6: case 7: case 8:
              res += 'D';
              for(int i=6; i<=d; i++)
                res += 'C';
             break;
            case 9:
              res += "CM";
             break;
           }
          num %= 100;
         }
        if(num>9)
         {
          d = num / 10;
          switch(d)
           {
            case 1: case 2: case 3:
              for(int i=1; i<=d; i++)
                res += 'X';
             break;
            case 4:
              res += "XL";
             break;
            case 5: case 6: case 7: case 8:
              res += 'L';
              for(int i=6; i<=d; i++)
                res += 'X';
             break;
            case 9:
              res += "XC";
             break;
           }
          num %= 10;
         }
        if(num>0)
         {
          d = num;
          switch(d)
           {
            case 1: case 2: case 3:
              for(int i=1; i<=d; i++)
                res += 'I';
             break;
            case 4:
              res += "IV";
             break;
            case 5: case 6: case 7: case 8:
              res += 'V';
              for(int i=6; i<=d; i++)
                res += 'I';
             break;
            case 9:
              res += "IX";
             break;
           }
          num = 0;
         }
        return res;
    }
};