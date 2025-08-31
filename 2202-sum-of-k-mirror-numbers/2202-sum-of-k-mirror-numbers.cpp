class Solution {
    bool isPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }

    string toBaseK(long long num, int k) {
        string s;
        while (num) {
            s += char((num % k) + '0');
            num /= k;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    long long createPalindrome(long long num, bool odd) {
        long long res = num;
        if (odd) num /= 10;
        while (num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long len = 1; n > 0; len *= 10) {
            for (long long i = len; n > 0 && i < len * 10; ++i) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(toBaseK(p, k))) {
                    sum += p;
                    --n;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; ++i) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(toBaseK(p, k))) {
                    sum += p;
                    --n;
                }
            }
        }
        return sum;
    }
};