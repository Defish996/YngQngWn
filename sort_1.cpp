#include <iostream>
#include <vector>
using namespace std;
//插入排序(升序)
//void InsertSort(int* a, int n)//利用插入排序将一个无序数组变有序
//{
//	for (int i = 1; i < n; i++)//一个元素没必要排序
//	{
//		int end = i - 1;//从最后一个开始比较排序
//		int tmp = a[i];//tmp表示该有效数组中的最后一个元素
//		while (end >= 0)
//		{
//			if (a[end] > tmp)//当前值大于最后一个,说明要在他的前面插入一个,给他留空间,当前值向后挪
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else//当前值要小于等于最后一个值了,不满足跳出
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;//当前值的下一个为要插入的位置
//	}
//}
//void ShellSort(int *a, int n)
//{
//	//预排序
//	int gap = 3;
//	for (int j = 0; j < gap; j++)//总共进行gap次排序
//	{
//		for (int i = j; i < n - gap; i += gap)//对第一次gap进行插入排序,让end从0开始,每次gap次跳跃进行排序
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = 3;
	for (int i = 0; i < n - gap; i++)
	{
		int end = i;//i < n - gap,所以不会越界
		int tmp = a[end + gap];//tmp为最后一个值
		while (end >= 0)
		{
			if (a[end] > tmp)//当前值大于最后一个,往后挪
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else//当前值小于或等于了,不满足循环,退出
			{
				break;
			}
		}
		a[end + gap] = tmp;//当前值要插入到当前位置的下一个gap处
	}
}
int main()
{
	int vec[11] = { 9,8,7,6,5,4,3,3,2,1,0 };
	//InsertSort(vec, 5);
	ShellSort(vec, sizeof(vec) / sizeof(int));



	return 0;
}