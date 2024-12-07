#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        map<char, int> mp_s, mp_t;

        for (char c : s) {
            mp_s[c]++;
        }
        for (char c : t) {
            mp_t[c]++;
        }

        return mp_s == mp_t;
    }
};
