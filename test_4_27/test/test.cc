#include<iostream>
#include<cstdio>
using namespace std;
long int arr[100000]{ 0 };
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    int i = 0;
    while (i < a) scanf("%d", arr + i++);
    long long int arrSum[100000]{ 0 };
    for (i = 1; i <= a; i++)
    {
        arrSum[i] = arrSum[i - 1] + arr[i - 1];

    }
    int x, y;
    while ((cin >> x >> y))
    {
        cout << arrSum[y] - arrSum[x - 1] << endl;
    }



    return 0;
}
