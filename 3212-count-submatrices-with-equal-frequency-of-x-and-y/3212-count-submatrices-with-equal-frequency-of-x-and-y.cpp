class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int countX = 0, countY = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<tuple<int,int,int>>> prefixSum(n,vector<tuple<int,int,int>>(m,make_tuple(0,0,0))); //{x,y,.}
        int result = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='X') prefixSum[i][j] = {1,0,0};
                else if(grid[i][j] == 'Y') prefixSum[i][j] = {0,1,0};
                else prefixSum[i][j] = {0,0,1};
                if(i > 0){
                    int prevX = get<0>(prefixSum[i-1][j]);
                    int prevY = get<1>(prefixSum[i-1][j]);
                    int prevDot = get<2>(prefixSum[i-1][j]);

                    get<0>(prefixSum[i][j]) += prevX;
                    get<1>(prefixSum[i][j]) += prevY;
                    get<2>(prefixSum[i][j]) += prevDot; 
                }
                if(j > 0){
                    int prevX = get<0>(prefixSum[i][j-1]);
                    int prevY = get<1>(prefixSum[i][j-1]);
                    int prevDot = get<2>(prefixSum[i][j-1]);

                    get<0>(prefixSum[i][j]) += prevX;
                    get<1>(prefixSum[i][j]) += prevY;
                    get<2>(prefixSum[i][j]) += prevDot; 
                }
                if(i > 0 && j > 0){
                    int prevX = get<0>(prefixSum[i-1][j-1]);
                    int prevY = get<1>(prefixSum[i-1][j-1]);
                    int prevDot = get<2>(prefixSum[i-1][j-1]);

                    get<0>(prefixSum[i][j]) -= prevX;
                    get<1>(prefixSum[i][j]) -= prevY;
                    get<2>(prefixSum[i][j]) -= prevDot; 
                }
                if(get<0>(prefixSum[i][j]) > 0 && get<0>(prefixSum[i][j]) == get<1>(prefixSum[i][j])) result++;
            }

        }
        return result;
    }
};