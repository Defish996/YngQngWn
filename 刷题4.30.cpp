//1329矩阵对角线排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> mat = { {3, 3, 1, 1},
                                {2, 2, 1, 2},
                                {1, 1, 1, 2}
    };

    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> vec(m + n);//开一个长为m+n列的二维,按从右上到左下对角线将数据放入
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec[i - j + m].push_back(mat[i][j]);//放入位置从中间开始放,最后全部放完是一个三角形,顶角向右
        }
    }
    for (auto& e : vec)//二维数组的排序方法
    {
        sort(e.rbegin(), e.rend());//vector不能取开头,只能从尾开始取,所以进行逆序排序
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = vec[i - j + m].back();
            vec[i - j + m].pop_back();
        }
    }
    for (auto& e : mat)
    {
        for (auto& n : e)
        {
            cout << n << " ";
        }
        cout << endl;
    }


	return 0;
}





//2798. 满足目标工作时长的员工数目   二分查找
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(),hours.end());
        int i = 0;
        int j = hours.size();
        while(i < j)
        {
            int mid = (i + j) / 2;
            if(hours[mid] < target)
            {
                i = mid+1;
            }
            else if(hours[mid]>target)
            {
                j = mid;
            }
            else if(hours[mid]==target)
            {
                
                j = mid;
            }

        }
        if(i==j)
        return hours.size()-j;
        return 0;
    }
};
