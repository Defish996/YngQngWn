#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
  fprintf(stdout,"fprintf:hello linux\n");
  printf("printf:hello linux\n");
  fputs("fputs:hello linux\n",stdout);

  const char* tmp = "write:hello linux\n";
  write(1,tmp,strlen(tmp));


  fork();


  return 0;
}




