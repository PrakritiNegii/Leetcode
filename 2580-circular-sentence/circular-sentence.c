bool isCircularSentence(char* sentence) 
{
   int l = strlen(sentence);
   int flag = 0;
   if(sentence[0]!=sentence[l-1]) return false;
   else flag = 1;
   for(int i=0; sentence[i]!='\0'; i++)
    {
     if(sentence[i]==' ')
      {
        if(sentence[i-1]==sentence[i+1])
         {
          flag = 1;
         }
        else 
         {
            flag = 0;
            break;
         }
      }
    }
  if(flag==0) return false;
  else return true;
}