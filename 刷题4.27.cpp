
//leetcode 2639
class Solution {
public:
int fun(int n)
    {
        int ans=0;
        if(n<0){
            n=-n;
            ans++;
        }
        if(n==0) return 1;
        while(n)
        {
            n/=10;
            ans++;
        }
        return ans;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i = 0; i <grid[0].size() ;i++)
        {
            for(int j = 0; j <grid.size() ;j++)
            {
                 ans[i]=max(ans[i],fun(grid[j][i]));
            }
        }
        return ans;
    }
};

//前缀和
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int arr[100000]{0};
    int a = 0, b = 0;
    cin >> a >> b;
    int i = 0;
    while(i<a) 
    {
        int tmp;
        scanf("%d",&tmp);
        arr[i] = tmp;
        i++;
    }
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