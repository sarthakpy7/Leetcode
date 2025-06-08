class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int ans = INT_MAX;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[lo] <= nums[mid]) {
                ans = min(ans, nums[lo]);
                lo = mid + 1;

            } else
                hi = mid - 1;
            ans = min(ans, nums[mid]);
        }
        return ans;
    }
};