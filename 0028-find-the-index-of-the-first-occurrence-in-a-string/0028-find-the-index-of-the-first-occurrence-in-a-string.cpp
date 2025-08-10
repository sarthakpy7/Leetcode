class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        const int d = 256;      // Alphabet size
        const int q = 101;      // A prime modulus for hash

        int h = 1;
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        int p = 0; // hash for needle
        int t = 0; // hash for substring of haystack

        // Calculate hash of needle and first window of haystack
        for (int i = 0; i < m; i++) {
            p = (d * p + needle[i]) % q;
            t = (d * t + haystack[i]) % q;
        }

        for (int i = 0; i <= n - m; i++) {
            // If hash matches, check the actual substring
            if (p == t) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false; break;
                    }
                }
                if (match) return i;
            }
            // Compute hash for next window
            if (i < n - m) {
                t = (d * (t - haystack[i] * h) + haystack[i + m]) % q;
                if (t < 0) t += q;
            }
        }
        return -1;
    }
};