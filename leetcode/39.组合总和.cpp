/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        vector<int> comb;
        sort(begin(candidates), end(candidates));
        recr(candidates, target, 0, comb, combs);
        return combs;
    }
private:
    void recr(const vector<int>& cands, int t, int next, vector<int>& comb, vector<vector<int>>& combs){
        if(t==0){
            combs.push_back(comb);
            return;
        }
        if(next == cands.size() || t-cands[next] <0) return;
        
        comb.push_back(cands[next]);
        recr(cands, t-cands[next], next, comb, combs);
        comb.pop_back();

        recr(cands, t, next+1, comb, combs);
    }
};
// @lc code=end

