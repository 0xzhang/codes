class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty()||array[0].empty()) return false;
        int r = 0, c = array[0].size()-1;
        while(r<array.size() && c>=0){
            if(target == array[r][c]) return true;
            else if(target < array[r][c]) --c;
            else ++r;
        }
        
        return false;
    }
};