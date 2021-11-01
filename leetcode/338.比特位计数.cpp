/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int off=0;
        for(int i=1; i<=n; ++i){
            if(!(i&(i-1))){
                off=0;
            }
            res[i] = 1+res[off++];
        }
        return res;
    }
};
// @lc code=end

