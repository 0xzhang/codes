/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int count=0;
                for(int r=max(i-1,0); r<min(i+2,m);++r)
                    for(int s=max(j-1,0); s<min(j+2,n);++s)
                        count += board[r][s]&1;
                if(count==3 || count-board[i][j]==3)
                    board[i][j] += 2;
            }
        }
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                board[i][j]>>=1;
    }
};
// @lc code=end

