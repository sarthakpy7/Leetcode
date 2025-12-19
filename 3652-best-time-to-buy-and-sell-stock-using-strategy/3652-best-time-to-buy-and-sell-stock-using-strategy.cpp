class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long actualP = 0;
        vector<long long> profit(n);

        for (int i = 0; i < n; i++) {
            profit[i] = (long long)strategy[i] * prices[i];
            actualP += profit[i];
        }

        long long originalWindProfit = 0;
        long long modifiedWindProfit = 0;
        long long maxGain = 0;

        int i = 0, j = 0;

        // sliding window
        while (j < n) {
            originalWindProfit += profit[j];

            // second half of the window contributes to modifiedWindProfit
            if (j - i + 1 > k / 2) {
                modifiedWindProfit += prices[j];
            }

            if (j - i + 1 > k) {
                originalWindProfit -= profit[i];
                modifiedWindProfit -= prices[i + k / 2];
                i++;
            }

            // evaluate window of size k
            if (j - i + 1 == k) {
                maxGain = max(maxGain, modifiedWindProfit - originalWindProfit);
            }

            j++;
        }

        return actualP + maxGain;
    }
};