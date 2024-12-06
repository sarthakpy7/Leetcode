#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
    }
};
