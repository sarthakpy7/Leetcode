class Solution {
public:
    int summ(vector<int>& nums, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // sum+=ceil(nums[i]/mid);
            sum += (nums[i] + mid - 1) / mid;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int hi=maxi;
        int ans =-1;
        while(lo<=hi){
            int mid=lo +((hi-lo)/2);
            if(summ(nums,mid)<=threshold){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};