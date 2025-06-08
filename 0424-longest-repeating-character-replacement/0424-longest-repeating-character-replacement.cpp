#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int l = 0, r = 0;
        int maxFreq = 0, maxLen = 0;

        while (r < s.size()) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // If number of letters to change > k, move left pointer
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
