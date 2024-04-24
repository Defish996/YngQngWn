#include<stdio.h>
#include<string.h>
int main()
{
  FILE* fp = fopen("bite.txt","w");
  if(fp==NULL)
  {
    perror("open");
    return 1;
  }
  char buffer[20] = "linux so easy!"; 
  
  size_t len = strlen(buffer); 
  fwrite(buffer,1,len,fp);

  fseek(fp,0,SEEK_SET);

  char tmp[20];
  fread(tmp,1,len,fp);
 
  buffer[len-1] = '\0';
  printf("%s\n",tmp);


  fclose(fp);




  return 0;
}
