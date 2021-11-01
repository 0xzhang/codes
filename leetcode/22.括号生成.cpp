/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        dfs(n, 0, str, res);

        return res;
    }
private:
    void dfs(int a, int b, string& str, vector<string>& res){
        if(!a&&!b){
            res.push_back(str);
            return;
        }
        if(a){
            str.push_back('(');
            dfs(a-1, b+1, str, res);
            str.pop_back();
        }
        if(b){
            str.push_back(')');
            dfs(a, b-1, str, res);
            str.pop_back();
        }
    }
};
// @lc code=end

