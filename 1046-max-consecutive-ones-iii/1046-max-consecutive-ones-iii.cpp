class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int z = 0;           // count of zeros
        int l = 0, r = 0;    // sliding window
        int mlen = 0;        // max length

        while (r < nums.size()) {
            if (nums[r] == 0) {
                z++;
            }

            if (z <= k) {
                // valid window
                mlen = max(mlen, r - l + 1);
            } else {
                // shrink window from left until z <= k again
                if (nums[l] == 0) {
                    z--;
                }
                l++;
            }

            r++;
        }

        return mlen;
    }
};
