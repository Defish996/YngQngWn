#include<iostream>
int main(int argc,char* argv[],char* env[])
{
  for(int i = 0;argv[i];i++)
  {
    std::cout << i << "->" << argv[i] << std::endl;
  }
  std::cout<<"--------------------"<<std::endl;
  for(int i = 0;env[i];i++)
  {

    std::cout << i << ":" << env[i] << std::endl;
  }



  return 0;
}
