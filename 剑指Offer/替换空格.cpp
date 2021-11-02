class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for(const auto &x : str)
            if(x == ' ') res+="%20";
            else res+=x;
        return res;
    }
};