#include <iostream>
#include <vector>
using namespace std;
//��������(����)
//void InsertSort(int* a, int n)//���ò�������һ���������������
//{
//	for (int i = 1; i < n; i++)//һ��Ԫ��û��Ҫ����
//	{
//		int end = i - 1;//�����һ����ʼ�Ƚ�����
//		int tmp = a[i];//tmp��ʾ����Ч�����е����һ��Ԫ��
//		while (end >= 0)
//		{
//			if (a[end] > tmp)//��ǰֵ�������һ��,˵��Ҫ������ǰ�����һ��,�������ռ�,��ǰֵ���Ų
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else//��ǰֵҪС�ڵ������һ��ֵ��,����������
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;//��ǰֵ����һ��ΪҪ�����λ��
//	}
//}
//void ShellSort(int *a, int n)
//{
//	//Ԥ����
//	int gap = 3;
//	for (int j = 0; j < gap; j++)//�ܹ�����gap������
//	{
//		for (int i = j; i < n - gap; i += gap)//�Ե�һ��gap���в�������,��end��0��ʼ,ÿ��gap����Ծ��������
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
		int end = i;//i < n - gap,���Բ���Խ��
		int tmp = a[end + gap];//tmpΪ���һ��ֵ
		while (end >= 0)
		{
			if (a[end] > tmp)//��ǰֵ�������һ��,����Ų
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else//��ǰֵС�ڻ������,������ѭ��,�˳�
			{
				break;
			}
		}
		a[end + gap] = tmp;//��ǰֵҪ���뵽��ǰλ�õ���һ��gap��
	}
}
int main()
{
	int vec[11] = { 9,8,7,6,5,4,3,3,2,1,0 };
	//InsertSort(vec, 5);
	ShellSort(vec, sizeof(vec) / sizeof(int));



	return 0;
}