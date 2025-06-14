int dp[12][2][12];  // dp[idx][tight][ct] to memoize the results

// Recursive function to count number of '1's
int solve(int idx, int tight, int ct, string &s) {
    // Base case: if we processed all digits, return the count of 1s seen
    if (idx == s.size()) return ct;

    // Return cached result if already computed
    if (dp[idx][tight][ct] != -1) return dp[idx][tight][ct];

    int lower = 0;
    int upper = (tight) ? s[idx] - '0' : 9;  // Upper bound based on tight condition
    int cnt = 0;

    // Try placing digits from lower to upper at current position
    for (int j = lower; j <= upper; j++) {
        // New tight will remain only if current digit matches the upper limit
        int newTight = tight && (j == upper);
        // Increment count if current digit is 1
        cnt += solve(idx + 1, newTight, ct + (j == 1), s);
    }

    return dp[idx][tight][ct] = cnt;  // Store result and return
}

class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);       // Convert number to string to access digits easily
        memset(dp, -1, sizeof(dp));    // Initialize DP table
        return solve(0, 1, 0, s);      // Start from index 0 with tight bound
    }
};