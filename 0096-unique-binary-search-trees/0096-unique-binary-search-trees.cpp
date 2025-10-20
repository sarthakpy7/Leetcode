class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int ans = 0;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i <= n; i++) {
            ans += f(i - 1, dp) * f(n - i, dp);
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {
        vector<int> dp(25, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] += dp[k-1] * dp[i-k];
            }
        }

        return dp[n];

        // return f(n, dp);
    }
};