class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> p;
        for(int i = 0; i < nums.size(); i++){
            if(p.count(nums[i])){
                ans.push_back(p[nums[i]]);
                ans.push_back(i);
                break;
            }
            p[target - nums[i]] = i;
        }
        return ans;
    }
};