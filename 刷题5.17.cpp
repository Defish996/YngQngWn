//leetcode 826. 安排工作以达到最大收益
//贪心 + STL pair,upper_bound,make_pair,lambda使用

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        //将这一对放进去<难度,利益>
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n; i++)
        {
            vec[i]={difficulty[i],profit[i]};
        }
        //利用first对pair进行排序
        //sort对pair类型默认是按照他的first来进行排序
        sort(vec.begin(),vec.end());
        
        //贪心思想的实现
        //将工作难度按从小到大实现,当vec内pair的second小于上次tmp
        //那么这个val下标所在second替换为tmp
        //也就是得到的利益相当于是tmp
        //那么这个利益也就到了最大化
        int tmp = vec[0].second;
        int ans = 0;
        for(int i = 0; i < n; i++)
        { 
            if(vec[i].second < tmp)
            {
                vec[i].second = tmp;
            }
            if(vec[i].second > tmp)
            {
                tmp = vec[i].second;
            } 
        }
        for(int i = 0; i < worker.size(); i++)
        {
            //upper_bound找到第一个大于这个val的迭代器下标
            int k = upper_bound(vec.begin(),vec.end(),make_pair(worker[i],0),[&](const pair<int,int>&p1,const pair<int,int>&p2)
            {return p1.first < p2.first;})-vec.begin();
            //生成pair用于比较,
            if(k==0) continue;
            ans+=vec[k-1].second;
        }
        return ans;


    }
};