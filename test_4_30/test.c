#include<ncurses.h>
int main()
{
  char c;
  initscr();//ncurses界面初始化
  printw("This is curses windows: \n");//在curses模式下的printf函数
  c=getch();//等待用户输入
  printw("you input: %c\n",&c);//用户输入一个字符
  getch();
  endwin();//程序退出





  return 0;
}
