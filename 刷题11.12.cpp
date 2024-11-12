// 3258. 统计满足 K 约束的子字符串数量 I


 
 class Solution {
 public:
     int countKConstraintSubstrings(string s, int k) {
         int n = s.size();
         int res = 0;
         for(int i = 0; i < n; ++i)
         {
             int cnt[2] = {0};
             for(int j = i; j < n; ++j)
             {
                 cnt[s[j] - '0']++;
                 if(cnt[0] > k && cnt[1] > k)
                 {
                     break;
                 }
                 res++;
             }
         }
         return res;
     }
 };