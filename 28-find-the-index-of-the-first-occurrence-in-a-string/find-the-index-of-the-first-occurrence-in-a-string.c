int strStr(char* haystack, char* needle) {
   int k = 0, pos = -1;
   int lh = strlen(haystack);
   int ln = strlen(needle);  
   if(lh>=ln) 
    {
   for(int i=0; haystack[i]!='\0'; i++)
    {
     if(haystack[i]==needle[k])
      {
       if(k==0) pos = i;
       k++;
      }
      else
       {
        if(k>0) i=pos;  //i increases by one in loop;
        k = 0;
        pos = -1;
       }
     if(k==ln) break;
    }
    }
  if(k==ln)
    return pos;
  else return -1;
}