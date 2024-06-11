//419. 甲板上的战舰   简单矩阵,还是不太熟练对矩阵题的应用,代码很简单,就是审题不严谨

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'X')//当当前节点是X,且当前X的左和上两个位置都是没有X,那么这个当前的X就可以认为是有效战舰数量.题目中要求没有相邻的战舰
                {
                    if(i > 0 && board[i - 1][j] == 'X')
                    {
                        continue;
                    }
                    if(j > 0 && board[i][j - 1] == 'X')
                    {
                        continue;
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};