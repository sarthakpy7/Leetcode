class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> pairSums;
        for (int i = 0; i < n - 1; ++i)
            pairSums.push_back((long long)weights[i] + weights[i + 1]);

        sort(pairSums.begin(), pairSums.end());

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; ++i) {
            minSum += pairSums[i];
            maxSum += pairSums[n - 2 - i];
        }

        return maxSum - minSum;
    }
};