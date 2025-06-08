class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1; // default to -1

        long long total = 1LL * m * k;
        if (total > bloomDay.size())
            return -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
