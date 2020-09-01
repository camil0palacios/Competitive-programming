class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(!s.count(nums[i])){
                v.emplace_back(nums[i]);
                s.insert(nums[i]);
            }
        }
        nums = v;
        return nums.size();
    }
};