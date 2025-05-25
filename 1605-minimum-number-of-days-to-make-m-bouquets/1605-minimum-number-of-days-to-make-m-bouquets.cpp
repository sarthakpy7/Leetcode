class Solution {
public:
    bool pos(vector<int>& bloomDay,int mid, int m, int k){
        int cnt=0;
        int nob=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                nob+=cnt/k;
                cnt=0;
            }
        }
        nob=nob+(cnt/k);
        if(nob>=m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(m*1LL*k*1LL))return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini = min(mini , bloomDay[i]);
            maxi = max(maxi , bloomDay[i]);
        }
        int lo=mini;
        int hi=maxi;
        int ans =hi;

        while(lo<=hi){
            int mid=lo + ((hi-lo)/2);

            if(pos(bloomDay,mid, m,k)==true){
                ans = mid ;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;  
    }
};