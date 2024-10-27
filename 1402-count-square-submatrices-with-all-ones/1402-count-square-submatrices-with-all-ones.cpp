#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

#define baburao_REPEAT__ganpatraooo(i,n) for(int i = 0; i < (n); i++)
#define baburao_RANGE__ganpatraooo(i,a,b) for(int i = (a); i <= (b); i++)
#define baburao_REV_RANGE__ganpatraooo(i,a,b) for(int i = (a); i >= (b); i--)
#define baburao_PUSH_BIT__ganpatraooo(num, pos) (num |= (1 << (pos)))
#define baburao_POP_BIT__ganpatraooo(num, pos) (num &= ~(1 << (pos)))
#define baburao_CHECK_BIT__ganpatraooo(num, pos) ((num >> (pos)) & 1)
#define baburao_ISOLATE_LAST__ganpatraooo(num) (num & (-num))
#define baburao_COUNT_ONES__ganpatraooo(num) (__builtin_popcount(num))
#define baburao_ALMOST_EQUAL__ganpatraooo(a, b) (fabs((a) - (b)) < 1e-9)

const int baburao_INFINITY__ganpatraooo = 1 << 29;
typedef long long baburao_lint__ganpatraooo;

inline int baburao_bit_shift__ganpatraooo(int n) { return 1 << n; }

class Solution {
public:
    int countSquares(vector<vector<int>>& baburao_matrix__ganpatraooo__apte) {
        int baburao_rows__ganpatraooo__apte = baburao_matrix__ganpatraooo__apte.size();
        int baburao_cols__ganpatraooo__apte = baburao_matrix__ganpatraooo__apte[0].size();
        
        vector<vector<int>> baburao_dpTable__ganpatraooo__apte(baburao_rows__ganpatraooo__apte, vector<int>(baburao_cols__ganpatraooo__apte, 0));
        int baburao_totalSquares__ganpatraooo__apte = 0;
        
        // Initialize first column of DP table
        for (int baburao_row__ganpatraooo = 0; baburao_row__ganpatraooo < baburao_rows__ganpatraooo__apte; baburao_row__ganpatraooo++) {
            baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo][0] = baburao_matrix__ganpatraooo__apte[baburao_row__ganpatraooo][0];
            baburao_totalSquares__ganpatraooo__apte += baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo][0];
        }
        
        // Initialize first row of DP table
        for (int baburao_col__ganpatraooo = 1; baburao_col__ganpatraooo < baburao_cols__ganpatraooo__apte; baburao_col__ganpatraooo++) {
            baburao_dpTable__ganpatraooo__apte[0][baburao_col__ganpatraooo] = baburao_matrix__ganpatraooo__apte[0][baburao_col__ganpatraooo];
            baburao_totalSquares__ganpatraooo__apte += baburao_dpTable__ganpatraooo__apte[0][baburao_col__ganpatraooo];
        }
        
        // Fill the DP table for remaining cells
        for(int baburao_row__ganpatraooo = 1; baburao_row__ganpatraooo < baburao_rows__ganpatraooo__apte; baburao_row__ganpatraooo++) {
            for(int baburao_col__ganpatraooo = 1; baburao_col__ganpatraooo < baburao_cols__ganpatraooo__apte; baburao_col__ganpatraooo++) {
                if(baburao_matrix__ganpatraooo__apte[baburao_row__ganpatraooo][baburao_col__ganpatraooo] == 1) {
                    baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo][baburao_col__ganpatraooo] = 
                        1 + min({baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo][baburao_col__ganpatraooo - 1],
                                 baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo - 1][baburao_col__ganpatraooo],
                                 baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo - 1][baburao_col__ganpatraooo - 1]});
                }
                baburao_totalSquares__ganpatraooo__apte += baburao_dpTable__ganpatraooo__apte[baburao_row__ganpatraooo][baburao_col__ganpatraooo];
            }
        }
        
        return baburao_totalSquares__ganpatraooo__apte;
    }
};
