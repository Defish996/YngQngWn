//274. H 指数 
//代码设计思路很巧妙,观察提议发现,他是在数据元素的大小之间进行判断,那么可以进行排序,这样能简便不少
//然后,定义一个h变量为0,从大端开始,得到满足条件的情况时,对h++,当在某次元素不满足情况时说明此后的元素也不会满足(因为是已经排完序的)
//所以直接退出循环
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        sort(citations.rbegin(), citations.rend());
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] > h)
            {
                ++h;
            }
            else break;
        }
        return h;
    }
};