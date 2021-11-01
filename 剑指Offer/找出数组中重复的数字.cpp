class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        
        for(const auto& x: nums)
            if(x<0||x>=n) return -1;
            
        for(int i=0;i<n;++i){
            while(i != nums[i] && nums[nums[i]] != nums[i]) swap(nums[nums[i]], nums[i]);
            if(i != nums[i] && nums[nums[i]] == nums[i]) return nums[i];
        }
        
        return -1;
    }
};