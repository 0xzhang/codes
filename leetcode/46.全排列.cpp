/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // Algorithm
        // sort(begin(nums), end(nums));
        // do{
        //     res.push_back(nums);
        // } while(next_permutation(begin(nums), end(nums)));

        // Recursive
        // vector<int> tmp;
        // vector<int> m(nums.size(), 0);
        // dfs(nums, 0, m, tmp, res);

        // Recursive2
        // dfs2(nums, 0, tmp, res);

        // Recursive3
        dfs3(nums, 0, res);

        return res;
    }
private:
    void dfs(vector<int>& nums, int p, vector<int>& m, vector<int>& tmp, vector<vector<int>>& res){
        if(p == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(!m[i]){
                m[i]=1;
                tmp.push_back(nums[i]);
                dfs(nums, p+1, m, tmp, res);
                tmp.pop_back();
                m[i]=0;
            }
        }
    }

    void dfs2(vector<int>& nums, int p, vector<int>& tmp, vector<vector<int>>& res){
        if(p == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<=tmp.size(); ++i){
            tmp.insert(begin(tmp)+i, nums[p]);
            dfs2(nums, p+1, tmp, res);
            tmp.erase(begin(tmp)+i);
        }
    }

    void dfs3(vector<int>& nums, int p, vector<vector<int>>& res){
        if(p == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=p; i<nums.size(); ++i){
            swap(nums[p], nums[i]);
            dfs3(nums, p+1, res);
            swap(nums[p], nums[i]);
        }
    }
};
// @lc code=end

