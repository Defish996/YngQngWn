// 今日一题 智能指针unique_ptr auto_ptr实现


//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //    vector<int > v1 = { 2,3,2 };
//    //      vector<int > v2 = { 1, 2 };
//    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
//        int m = nums1.size(), n = nums2.size();
//        vector<int> ans(2, 0);
//        for(int i = 0; i < m; i++) {
//            for(int j = 0; j < n; j++){
//                if(nums1[i] == nums2[j]) {
//                    ans[0]++;
//                    break;
//                }
//            }
//        }
//
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++){
//                if(nums2[i] == nums1[j]) {
//                    ans[1]++;
//                    break;
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int > v1 = { 2,3,2 };
//    vector<int > v2 = { 1, 2 };
//    s.findIntersectionValues(v1, v2);
//
//
//
//}
//
//
//

#include <iostream>
#include <string>
#include "SmartPtr.h"
using namespace std;
void Test1()
{
	SmartPtr<int> ptr(new int);
	*ptr = 1;

	SmartPtr<pair<string, int>> ptr2(new pair<string, int>("xxxxx", 1));

	//等价于
	// ptr2.operator->()->first += "y";
	ptr2->first += "y";
	ptr2->second += 2;


}
void Test2()
{
	SmartPtr<int> ptr1(new int);
	SmartPtr<int> ptr2 = ptr1;
	(*ptr1)++;
	(*ptr1)++;
}
void Test3()
{
	unique_ptr<int> ptr1(new int);
	unique_ptr<int> ptr2 = ptr1;
}
int main()
{
	//Test1();
	//Test2();
	Test3();


	return 0;
}
