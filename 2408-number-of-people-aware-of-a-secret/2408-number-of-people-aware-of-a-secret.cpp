class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int totalPersons = 1; // Total number of people who know the secret on the i-th day
        int activePersons = 0; // Number of people who can share the secret on the i-th day
        int MOD = 1e9 + 7;

        // tracker[i].first  -> number of people forgetting the secret on day i
        // tracker[i].second -> number of people becoming eligible to share on day i
        vector<pair<int, int>> tracker(n);


        if (delay < n)
            tracker[delay] = {0, 1};
        if (forget < n)
            tracker[forget] = {1, 0};

        for (int i = 1; i < n; i++) {
            // Remove people who forget the secret today
            totalPersons = (totalPersons - tracker[i].first + MOD) % MOD;
            activePersons = (activePersons - tracker[i].first + MOD) % MOD;

            // Add people who become eligible to share today
            activePersons = (activePersons + tracker[i].second) % MOD;

            // Each active person shares the secret with one new person
            totalPersons = (totalPersons + activePersons) % MOD;

            // People learning the secret today become eligible after `delay` days
            if (i + delay < n)
                tracker[i + delay].second = activePersons;

            // People learning the secret today forget it after `forget` days
            if (i + forget < n)
                tracker[i + forget].first = activePersons;
        }
        return totalPersons;
    }
};