#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;
        int n = s.size();
        
        // Generate all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                
                // Check if the substring is "special"
                if (isSpecial(sub)) {
                    freq[sub]++;
                }
            }
        }
        
        // Find the longest "special" substring that occurs at least thrice
        int maxLength = -1;
        for (const auto& [key, value] : freq) {
            if (value >= 3) {
                maxLength = max(maxLength, (int)key.length());
            }
        }
        
        return maxLength;
    }

private:
    // Check if a string is "special" (all characters are identical)
    bool isSpecial(const string& str) {
        char firstChar = str[0];
        for (char c : str) {
            if (c != firstChar) return false;
        }
        return true;
    }
};
