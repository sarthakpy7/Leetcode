class Solution {
public:
    // Helper function to check if `mid` time can complete the required trips
    bool check(long long mid, vector<int>& time, int totalTrips) {
        long long total_trips = 0;
        for (int t : time) {
            total_trips += mid / t; // Calculate trips made by each bus in `mid` time
            if (total_trips >= totalTrips) return true; // Early exit if condition is met
        }
        return total_trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1;
        long long hi = 1LL * *min_element(time.begin(), time.end()) * totalTrips; // Upper bound
        long long ans = -1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2; // Midpoint to avoid overflow
            if (check(mid, time, totalTrips)) {
                ans = mid;  // Update the answer
                hi = mid - 1; // Search in the left half
            } else {
                lo = mid + 1; // Search in the right half
            }
        }

        return ans;
    }
};
