class puzzle{
   public: 
    vector<vector<int>> v;
    pair<int,int> position;
    int count;
    string visited;

    puzzle(vector<vector<int>> n, int c){
        v = n;
        count = c;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                visited+=to_string(v[i][j]);
                if(v[i][j]==0){
                    position = {i,j} ;
                }
            }
        }
    }
};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<puzzle> q;
        unordered_map<string,int> m;
        vector<vector<int>> final = {{1,2,3},{4,5,0}};

        puzzle k = puzzle(board,0);
        m[k.visited]=1;
        q.push(k);
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.v==final) return t.count;
            auto matrix = t.v;
            auto pos = t.position;
            for(int i = 0;i<4;i++){
                int x_new = pos.first + dx[i];
                int y_new = pos.second + dy[i];
                if(x_new >=0 && x_new < 2 && y_new >=0 && y_new < 3){
                    swap(matrix[pos.first][pos.second],matrix[x_new][y_new]);
                    puzzle w = puzzle(matrix,t.count+1);
                    if(!m.count(w.visited)){
                        m[w.visited]=1;
                        q.push(w);
                    }
                    swap(matrix[x_new][y_new],matrix[pos.first][pos.second]);
                }
            }



        }
        return -1;


    }
};