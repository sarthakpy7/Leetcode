class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(); 
        int lo=0;
        int hi=n-1;
        
        while(lo<=hi){
        int mid = (lo+hi)/2;
        if(nums[mid]==target)return true;
        if(nums[lo]==nums[mid] && nums[mid]==nums[hi]) {
            lo++;
            hi--;
            continue;
        }
              //left sorted
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && nums[mid]>= target)
                hi=mid-1;
                else 
                lo=mid+1;
            }
              //right sorted
              if(nums[hi]>=nums[mid])
              if(nums[hi]>=target && nums[mid]<=target)
              {lo=mid+1;}
              else { 
              hi=mid-1;   
              }

        }
      return false;

    }
};