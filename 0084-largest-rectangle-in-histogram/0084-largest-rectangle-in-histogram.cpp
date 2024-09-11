class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psm(n); // Previous smaller element index
        vector<int> nsm(n); // Next smaller element index
        
        // Compute psm (Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            int val = i - 1;
            while (val != -1 && heights[val] >= heights[i]) {
                val = psm[val];
            }
            psm[i] = val;
        }

        // Compute nsm (Next Smaller Element)
        for (int i = n - 1; i >= 0; i--) {
            int val = i + 1;
            while (val != n && heights[val] >= heights[i]) {
                val = nsm[val];
            }
            nsm[i] = val;
        }

        // Calculate the maximum area
        long long area = 0;
        for (int i = 0; i < n; i++) {
            long long height = heights[i];
            long long width = nsm[i] - psm[i] - 1;
            area = max(area, height * width);
        }

        return area;
    }
};
