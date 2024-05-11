//leetcode 2391. 收集垃圾的最少总时间
class Sum
{
public:
    Sum()
        :m(0)
        , p(0)
        , g(0)
    {}
public:
    int m;
    int p;
    int g;
};
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<Sum> sum(garbage.size());
        int i = 0, ans = 0, t = travel.size(), sumM = 0, sumP = 0, sumG = 0;
        for (const string& e : garbage)
        {
            for (const char& c : e)
            {
                if (c == 'M') 
                {
                    ++sum[i].m;
                    ++sumM;
                }
                else if (c == 'P')
                {
                    ++sum[i].p;
                    ++sumP;
                }
                else if (c == 'G')
                {
                    ++sum[i].g;
                    ++sumG;
                }
            }
            ++i;
        }
        for (i = 0; i < sum.size(); i++)
        {
            if (sum[i].m != 0 && sum[i].p != 0 && sum[i].g != 0)//都有
            {
                ans += sum[i].m + sum[i].p + sum[i].g;
                sumM -= sum[i].m;
                sumP -= sum[i].p;
                sumG -= sum[i].g;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m == 0 && sum[i].p != 0 && sum[i].g != 0)//去掉m
            {
                ans += sum[i].g + sum[i].p;
                sumP -= sum[i].p;
                sumG -= sum[i].g;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m == 0 && sum[i].p == 0 && sum[i].g != 0)//去掉m和p
            {
                ans += sum[i].g;
                sumG -= sum[i].g;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m == 0 && sum[i].p != 0 && sum[i].g == 0)//去掉m和g
            {
                ans += sum[i].p;
                sumP -= sum[i].p;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m != 0 && sum[i].p == 0 && sum[i].g != 0)//去掉p
            {
                ans += sum[i].m + sum[i].g;
                sumM -= sum[i].m;
                sumG -= sum[i].g;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m != 0 && sum[i].p == 0 && sum[i].g == 0)//去掉p和g
            {
                ans += sum[i].m;
                sumM -= sum[i].m;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
            else if (sum[i].m != 0 && sum[i].p != 0 && sum[i].g == 0)//去掉g
            {
                ans += sum[i].m + sum[i].p;
                sumM -= sum[i].m;
                sumP -= sum[i].p;
                if (sumM && sumP && sumG) ans += 3 * travel[i];
                else if ((sumM && sumP) || (sumP && sumG) || (sumM && sumG)) ans += 2 * travel[i];
                else if (sumM || sumP || sumG) ans += travel[i];
                else break;
            }
        }
        return ans;
    }
};