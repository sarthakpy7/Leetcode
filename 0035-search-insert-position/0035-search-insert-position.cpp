class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = n;

        while (lo<=hi){
            int mid = lo + ((hi-lo)/2);

            if (nums[mid]>=x){
            ans = mid ;
            hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans ;
    }
    
};