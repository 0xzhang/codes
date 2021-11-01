/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // Algorithm
        // reverse(begin(s), end(s));
        // 交换一半
        int n = s.size();
        for(int i=0; i < (n>>1); ++i){
            swap(s[i], s[n-i-1]);
        }
        // 双指针
        // int i=0, j=s.size()-1;
        // while(i<j) swap(s[i++], s[j--]);
    }
};
// @lc code=end

