char* makeFancyString(char* s) {
    int l = strlen(s);
    char *fs = (char*) malloc((l+1)*sizeof(char));
    int c = 1, j = 0, i;
    for(i=0; i<l; i++)
     {
      if(c<=2)
       {
        fs[j] = s[i];
        j++;
       }
      if(s[i]==s[i+1])
        c++;
      else
        c = 1;
     }
    fs[j] = '\0';
    return fs;
}