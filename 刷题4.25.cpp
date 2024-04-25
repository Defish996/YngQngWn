leetcode 2739
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int sum = 0;
        while(mainTank>0)
        {
            int consult = mainTank - 5;
            if(consult<0)
            {
                sum += mainTank*10;
                return sum;
            }
            sum += 50;
            if(additionalTank>0)
            {
                mainTank++;
                additionalTank--;
            }
            mainTank-=5;
        }
        return sum;

    }
};



蓝桥杯官网
1.密码破译
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        scanf("%d", &tmp);
        printf("%c", 'a' + tmp - 1);

    }

    return 0;
}

2.约数个数
#include <iostream>
using namespace std;
int main()
{
  int sum = 0;
  for(int i = 1; i <= 2023; i++)
  {
    if(2023%i==0)
    {
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}