class Solution {
public:
    long long maxHeight(long long T, vector<int>& workerTimes){
        long long total = 0;
        
        for(long long t : workerTimes){
            long long k = (2 * T) / t;
            
            long long x = (sqrt(1 + 4.0 * k) - 1) / 2;
            
            total += x;
            if(total >= 1e5) break;
        }
        
        return total;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18;
        long long ans = r;
        
        while(l <= r){
            long long mid = l + (r - l) / 2;
            
            if(maxHeight(mid, workerTimes) >= mountainHeight){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};