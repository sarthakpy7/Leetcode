class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0; 
        
        int low = 0, high = size - 1; 
        
        while (low < high) {
            int mid = low + (high - low) / 2; 
           
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid; 
            }
        }
        
        return low; 
    }
};
