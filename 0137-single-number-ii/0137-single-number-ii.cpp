class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<32;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += (nums[j] >> i) & 1;
            }
            sum %= 3;
            if(sum == 1) ans |= sum << i;
        }
        return ans;
    }
};