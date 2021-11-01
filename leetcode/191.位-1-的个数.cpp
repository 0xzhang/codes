/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t i) {
        // Fast1
        // i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
        // i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        // i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
        // i = (i * (0x01010101) >> 24);
        // return i;

        int res=0;
        // Fast2
        // while(i){
        //     i &= (i-1);
        //     ++res;
        // }
        // Regular
        for(int t=0;t<32;++t){
            if(i&1) ++res;
            i>>=1;
        }
        return res;
    }
};
// @lc code=end

