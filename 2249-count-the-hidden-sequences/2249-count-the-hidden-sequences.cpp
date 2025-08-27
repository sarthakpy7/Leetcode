class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0;
        long long minPref = 0, maxPref = 0;
        
        // Build prefix‐sums and track min/max
        for (int d : differences) {
            prefix += d;
            minPref = min(minPref, prefix);
            maxPref = max(maxPref, prefix);
        }
        
        // width = maxPref - minPref
        long long width = maxPref - minPref;
        
        // Number of valid x in [ lower - minPref, upper - maxPref ]
        long long total = (upper - lower) - width + 1;
        return total > 0 ? (int)total : 0;
    }
};