class Solution {
public:

    void solve(vector<int> nums, int i, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int j=i;j<nums.size();j++) {
            if(j>i && nums[j]==nums[j-1])continue;
            curr.push_back(nums[j]);
            solve(nums,j+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> curr;
        solve(nums,0,curr, res);
        return res;
    }
};