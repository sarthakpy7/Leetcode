class Solution {
public:

    void solve(vector<int>& nums, int start, int sum, int target,
               vector<int>& curr, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(curr);
        }
        if (start >= nums.size())
            return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            if (sum + nums[i] > target)
                break;
            curr.push_back(nums[i]);
            solve(nums, i + 1, sum + nums[i], target, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates, 0, 0, target, curr, res);
        return res;
    }
};