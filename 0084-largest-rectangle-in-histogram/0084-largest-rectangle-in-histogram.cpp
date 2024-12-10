#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int nsm[n];
         for(int i=n-1;i>=0;i--){
            int val=i+1;
            while(val!=n && heights[val] >= heights[i]){
                val = nsm[val];
            }
            nsm[i]=val;
         }
        int psm[n];
        for(int i=0;i<n;i++){
            int val=i-1;
            while(val!=-1 && heights[val] >= heights[i]){
                val = psm[val];
            }
            psm[i]=val;
         }

         int area=0;
         for(int i=0;i<n;i++){
            int height = heights[i];
            int width = nsm[i] - psm[i] - 1;
            area = max(area, height*width);
         }
         return area;


    }
};