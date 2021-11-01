/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Iterative
        vector<vector<int>> subs = {{}};
        for(int num : nums){
            int n = subs.size();
            for(int i = 0; i < n; ++i){
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }

        // Bit Manipulation
        // int n = nums.size();
        // int b = 1<<n;
        // vector<vector<int>> subs(b);
        // for(int i = 0; i < b; ++i)
        //     for(int j = 0; j < n; ++j)
        //         if((i>>j)&1) subs[i].push_back(nums[j]);

        // Recursive
        // vector<vector<int>> subs;
        // vector<int> sub;
        // subsets(nums, 0, sub, subs);   

        // Recursive2
        // vector<vector<int>> subs;
        // subsets2(nums, 0, 1<<nums.size(), subs);

        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int j=i; j<nums.size(); ++j){
            sub.push_back(nums[j]);
            subsets(nums, j+1, sub, subs);
            sub.pop_back();
        }
    }

    void subsets2(vector<int>& nums, int i, int b, vector<vector<int>>& subs){
        subs.push_back({});
        for(int j=0; j<nums.size(); ++j)
            if((b>>j)&1) subs.back().push_back(nums[j]);
        for(int j=i; j<nums.size(); ++j){
            b += (1<<j);
            subsets2(nums, j+1, b, subs);
            b -= (1<<j);
        }
    }
};
// @lc code=end

