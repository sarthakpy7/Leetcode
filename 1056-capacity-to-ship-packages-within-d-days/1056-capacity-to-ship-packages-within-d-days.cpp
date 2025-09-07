class Solution {
public:
    int sum(vector<int>& weights) {
        int add = 0;
        for (int w : weights) add += w;
        return add;
    }

    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1, load = 0;
        for (int w : weights) {
            if (load + w > capacity) {  // new day
                dayCount++;
                load = 0;
            }
            load += w;
        }
        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int hi = sum(weights);
        int lo = *max_element(weights.begin(), weights.end());
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // capacity
            if (canShip(weights, days, mid)) {
                ans = mid;   // valid capacity, try smaller
                hi = mid - 1;
            } else {
                lo = mid + 1; // too small, increase capacity
            }
        }
        return ans;
    }
};
