#include <bits/stdc++.h>
using namespace std;

// Custom Typedefs and Macros
using sarthak_int = long long;
#define sar_int sarthak_int
#define sar_vec vector<sarthak_int>
#define sar_pvec vector<pair<sarthak_int, sarthak_int>>
#define sar_map map<sarthak_int, sarthak_int>
#define sar_all(v) v.begin(), v.end()
#define sar_sz(v) (sarthak_int)(v.size())
#define sar_nline cout << "\n";
#define sar_out(x) {cout << x << ' '; }
#define sar_outln(x) {cout << x << "\n"; }
#define sar_iter(v) {for (auto& sarthak_elem : v) sar_out(sarthak_elem); sar_nline}

// Constants
const sarthak_int SAR_MOD = 1e9 + 7;
const sarthak_int SAR_INF = 1e18;
const sarthak_int SAR_INT_MIN = LLONG_MIN;
const sarthak_int SAR_INT_MAX = LLONG_MAX;

// Utility Functions
sarthak_int sar_gcd(sarthak_int a, sarthak_int b) { return b == 0 ? a : sar_gcd(b, a % b); }
sarthak_int sar_pow(sarthak_int base, sarthak_int exp, sarthak_int mod = SAR_MOD) { 
    sarthak_int res = 1; 
    while (exp) { 
        if (exp & 1) res = (res * base) % mod; 
        base = (base * base) % mod; 
        exp >>= 1; 
    } 
    return res; 
}
sarthak_int sar_lcm(sarthak_int a, sarthak_int b) { return (a / sar_gcd(a, b)) * b; }

// Modular Arithmetic
sarthak_int sar_mod_add(sarthak_int a, sarthak_int b, sarthak_int mod = SAR_MOD) { return (((a % mod + b % mod) % mod) + mod) % mod; }
sarthak_int sar_mod_mul(sarthak_int a, sarthak_int b, sarthak_int mod = SAR_MOD) { return (((a % mod * b % mod) % mod) + mod) % mod; }
sarthak_int sar_mod_sub(sarthak_int a, sarthak_int b, sarthak_int mod = SAR_MOD) { return (((a % mod - b % mod) % mod) + mod) % mod; }
sarthak_int sar_mod_div(sarthak_int a, sarthak_int b, sarthak_int mod = SAR_MOD) { return sar_mod_mul(a, sar_pow(b, mod - 2, mod), mod); }

class Solution {
public:
    int divide(int dividend, int divisor) {
       
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

       
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        
        sarthak_int absDividend = abs((sarthak_int)dividend);
        sarthak_int absDivisor = abs((sarthak_int)divisor);

     
        sarthak_int quotient = 0;
        while (absDividend >= absDivisor) {
            sarthak_int tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            quotient += multiple;
        }
        return isNegative ? -quotient : quotient;
    }
};


