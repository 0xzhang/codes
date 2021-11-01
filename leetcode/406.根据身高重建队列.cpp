/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), cmp);
        vector<vector<int>> res;
        for(auto x:people){
            res.insert(res.begin()+x[1], x);
        }
        return res;
    }
private:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]) return a[1]<b[1];
        else return a[0] > b[0];
    }
};
// @lc code=end

