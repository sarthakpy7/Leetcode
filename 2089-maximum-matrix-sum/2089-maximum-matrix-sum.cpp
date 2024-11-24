#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0; 
        int numNegatives = 0;  
        int smallestAbsValue = INT_MAX; 

        
        for (const auto& row : matrix) {
            for (int value : row) {
                totalSum += abs(value); 

            
                if (value < 0) {
                    numNegatives++;
                }

                
                smallestAbsValue = min(smallestAbsValue, abs(value));
            }
        }

       
        if (numNegatives % 2 == 1) {
            totalSum -= 2 * smallestAbsValue; 
        }

        return totalSum;
    }
};