class Solution {
public:
   int maxelem(vector<vector<int>>& mat , int n , int m , int col){
    int maxi=-1;
    int index=-1;
    for(int i =0; i<n ; i++)
    {
        if(mat[i][col]>maxi){
            maxi=mat[i][col];
            index=i;
        }
    }
    return index;
   }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size();
            int lo = 0;
            int hi = m - 1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int maxind = maxelem(mat, n, m, mid);
                int left = mid - 1 >= 0 ? mat[maxind][mid - 1] : -1;
                int right = mid + 1 < m ? mat[maxind][mid + 1] : -1;

                if (mat[maxind][mid] > left && mat[maxind][mid] > right) {
                    return {maxind, mid} ;
                } 
                else if (mat[maxind][mid] < left) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return {-1, -1 };
        
    }
};