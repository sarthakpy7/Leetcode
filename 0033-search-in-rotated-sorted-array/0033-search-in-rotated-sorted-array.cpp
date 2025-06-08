class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target == nums[mid]){
                ans = mid;
                return ans;    
            }
            if (nums[lo] <= nums[mid]) {
                if(target >= nums[lo] && target <= nums[mid]){
                    hi=mid-1;
                }
                else lo=mid+1;
            } else {
                if(target<=nums[hi] && target >= nums[mid]){
                    lo=mid+1;
                }
                else{hi=mid-1;}
            }
        }
        return -1;
    }
};