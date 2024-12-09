class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=2;
        if (nums.size() <= 2) return nums.size();
        for(int i=2;i<nums.size();i++){
            if(nums[k-2]!=nums[i]){
                nums[k]=nums[i];
                k++;
            }
        
        }
        return k;
    }
};