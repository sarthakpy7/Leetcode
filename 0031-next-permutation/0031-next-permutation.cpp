#include <vector>
#include <algorithm> // for next_permutation
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {   
            sort(nums.begin(), nums.end());
        }
    }
};
